#ifndef ___BLOCK_HANDLER__HPP___
#define ___BLOCK_HANDLER__HPP___

#include <boost/lexical_cast.hpp>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include "VPRNetParser.hpp"

using namespace std;

enum PinClass { PIN_IN, PIN_OUT, PIN_GLOBAL };

typedef map<PinClass, set<int> > pin_class_map_t;
typedef map<int, PinClass> pin_class_reverse_map_t;
typedef map<string, int> net_label_map_t;
typedef map<string, int> block_label_map_t;
typedef vector<vector<int> > net_to_block_indexes_t;
typedef vector<vector<int> > block_to_net_indexes_t;


class NetlistReader {
public:
    VPRNetParser p;
    ifstream *in_stream;

    int funcblock_count;
    int input_count;
    int output_count;
    int global_count;

    int net_count;
    int block_count;

    int net_index;
    int block_index;

    pin_class_map_t pin_class_map_;
    pin_class_reverse_map_t pin_class_reverse_map_;
    vector<string> net_labels_;
    net_label_map_t net_label_map_;
    block_label_map_t block_label_map_;
    net_to_block_indexes_t net_to_block_indexes_;
    block_to_net_indexes_t block_to_net_indexes_;

    NetlistReader(string input_filename) :
            net_index(0), block_index(0),
            funcblock_count(0), input_count(0),
            output_count(0), global_count(0) {
        this->in_stream = new ifstream(input_filename.c_str());
        init_pin_class_map();
        p = VPRNetParser(32 << 10);
    }

    void reset() {
        net_index = 0;
        block_index = 0;
    }

    void init_pin_class_map() {
        /*
         * Manually set pin locations for "clb" tiles based on `k4-n1.xml`:
         *
         *     <pinclasses>
         *         <class type="in">0 1 2 3 </class>
         *         <class type="out">4 </class>
         *         <class type="global">5 </class>
         *     </pinclasses>
         */
        set<int> pins;
        for (int i = 0; i < 4; i++) {
            pins.insert(i);
        }
        this->pin_class_map_[PIN_IN] = pins;

        pins.clear();
        pins.insert(4);
        this->pin_class_map_[PIN_OUT] = pins;

        pins.clear();
        pins.insert(5);
        this->pin_class_map_[PIN_GLOBAL] = pins;

        set<int>::iterator pin_iter;

        PinClass pin_classes[3] = {PIN_IN, PIN_OUT, PIN_GLOBAL};

        for(int i = 0; i < 3; i++) {
            PinClass p = pin_classes[i];
            for(pin_iter = this->pin_class_map_[p].begin();
                pin_iter != this->pin_class_map_[p].end(); pin_iter++) {
                this->pin_class_reverse_map_[*pin_iter] = p;
            }
        }
    }

    void rewind() {
        reset();
        in_stream->clear();
        in_stream->seekg(0, ios::beg);
    }

    /* Count pass: START */
    void count_pass() {
        p.init();
        p.register_input_process_func(boost::bind(&NetlistReader::count_process_input, this, _1, _2));
        p.register_output_process_func(boost::bind(&NetlistReader::count_process_output, this, _1, _2));
        p.register_funcblock_process_func(boost::bind(&NetlistReader::count_process_funcblock, this, _1, _2, _3, _4));
        p.register_global_process_func(boost::bind(&NetlistReader::count_process_global, this, _1));
        p.parse(*in_stream);
        net_count = net_index;
        block_count = block_index;
    }

    void count_process_funcblock(const string &funcblocktype,
            const string &label, const vector<string> &pins,
            const vector<SubBlock> &subblocks) {
        funcblock_count++;
        for(int i = 0; i < pins.size(); i++) {
            const PinClass pin_class = this->pin_class_reverse_map_[i];
            if(pins[i] != "open" && pin_class == PIN_OUT) {
                net_index++;
            }
        }
        block_index++;
    }

    void count_process_input(const string &label, const vector<string> &pins) {
        input_count++;
        net_index++;
        block_index++;
    }

    void count_process_output(const string &label, const vector<string> &pins) {
        output_count++;
        block_index++;
    }

    void count_process_global(const string &label) {
        global_count++;
    }
    /* Count pass: END */

    /* Load pass: START */
    void load_pass() {
        block_to_net_indexes_.resize(block_count);
        net_to_block_indexes_.resize(net_count);
        net_labels_.resize(net_count);

        p.init();
        p.register_input_process_func(boost::bind(&NetlistReader::load_process_input, this, _1, _2));
        p.register_output_process_func(boost::bind(&NetlistReader::load_process_output, this, _1, _2));
        p.register_funcblock_process_func(boost::bind(&NetlistReader::load_process_funcblock, this, _1, _2, _3, _4));
        p.parse(*in_stream);
    }

    void load_process_funcblock(const string &funcblocktype,
            const string &label, const vector<string> &pins,
            const vector<SubBlock> &subblocks) {
        for(int i = 0; i < pins.size(); i++) {
            const PinClass pin_class = this->pin_class_reverse_map_[i];
            if(pins[i] != "open" && pin_class == PIN_OUT) {
                load_process_net(pins[i]);
                net_index++;
            }
        }
        block_index++;
    }

    void load_process_input(const string &label, const vector<string> &pins) {
        load_process_net(pins[0]);
        net_index++;
        block_index++;
    }

    void load_process_output(const string &label, const vector<string> &pins) {
        block_index++;
    }

    void load_process_net(const string &label) {
        this->net_labels_[net_index] = label;
        this->net_label_map_[label] = net_index;
    }
    /* Load pass: END */

    /* Map pass: START */
    void map_pass() {
        p.init();
        p.register_input_process_func(boost::bind(&NetlistReader::map_process_input, this, _1, _2));
        p.register_output_process_func(boost::bind(&NetlistReader::map_process_output, this, _1, _2));
        p.register_global_process_func(boost::bind(&NetlistReader::map_process_global, this, _1));
        p.register_funcblock_process_func(boost::bind(&NetlistReader::map_process_funcblock, this, _1, _2, _3, _4));
        p.parse(*in_stream);
    }

    void map_process_funcblock(const string &funcblocktype,
            const string &label, const vector<string> &pins,
            const vector<SubBlock> &subblocks) {
        // Fill block-to-net-index vector
        for(int i = 0; i < pins.size(); i++) {
            if(pins[i] != "open") {
                const PinClass pin_class = this->pin_class_reverse_map_[i];
                if(pin_class == PIN_OUT) {
                    // This block has an output pin assigned to a net, so
                    // increment the overall net-count.
                    net_index++;
                }
                block_to_net_indexes_[block_index].push_back(net_label_map_[pins[i]]);
            }
        }
        block_index++;
    }

    void map_process_input(const string &label, const vector<string> &pins) {
        block_to_net_indexes_[block_index].push_back(net_label_map_[pins[0]]);

        // Every input drives a net, so increment the overall net-count
        net_index++;
        block_index++;
    }

    void map_process_output(const string &label, const vector<string> &pins) {
        block_to_net_indexes_[block_index].push_back(net_label_map_[pins[0]]);
        block_index++;
    }

    void map_process_global(const string &label) {
        // Do nothing (for now)
    }

    /* Map pass: END */

    //vpr::NetList parse() {
    void parse() {
        count_pass();
        rewind();
        load_pass();
        rewind();
        map_pass();

        /* Builds mappings from each net-to-block-indexes to the blocks contained */
        //sync_nets_to_blocks();
    }

    ~NetlistReader() {
        this->in_stream->close();
    }

    /* This function updates the nets list to point back to blocks list */
#if 0
    void sync_nets_to_blocks() {
        using namespace std;

        int i, j, k, l;
        t_type_ptr cur_type;

        /* Count the number of sinks for each net */
        for(j = 0; j < block_list.size(); ++j) {
            cur_type = block_list[j].type;
            for(k = 0; k < cur_type->num_pins; ++k) {
                if(RECEIVER == cur_type->class_inf[cur_type->pin_class[k]].type) {
                    int i = block_list[j].nets[k];
                    if(OPEN != i) {
                        ++net_list[i].num_sinks;
                    }
                }
            }
        }

        /* Alloc and load block lists of nets */
        vector<int> net_l(net_list.size(), 1); /* First sink goes at position 1, since 0 is for driver */

        for(j = 0; j < block_list.size(); ++j) {
            cur_type = block_list[j].type;
            for(k = 0; k < cur_type->num_pins; ++k) {
                int i = block_list[j].nets[k];
                if(OPEN != i) {
                    /* The list should be num_sinks + 1 driver. Re-alloc if already allocated. */
                    int num_sinks = net_list[i].num_sinks;
                    if(NULL == net_list[i].node_block) {
                        net_list[i].node_block = (int *)my_malloc(sizeof(int) * (num_sinks + 1));
                    }
                    if(NULL == net_list[i].node_block_pin) {
                        net_list[i].node_block_pin = (int *)my_malloc(sizeof(int) * (num_sinks + 1));
                    }
                    if(RECEIVER == cur_type->class_inf[cur_type->pin_class[k]].type) {
                        l = net_l[i];
                        net_list[i].node_block[l] = j;
                        net_list[i].node_block_pin[l] = k;
                        ++net_l[i];
                    } else {
                        assert(DRIVER == cur_type->class_inf[cur_type->pin_class[k]].type);
                        net_list[i].node_block[0] = j;
                        net_list[i].node_block_pin[0] = k;
                    }
                }
            }
        }
    }
#endif
};


#endif
