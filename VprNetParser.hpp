#ifndef ___VPR_NET_PARSER__HPP___
#define ___VPR_NET_PARSER__HPP___

#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <string.h>
#include <stdlib.h>

using namespace std;

#define DEF_BUFSIZE 32 << 10

struct SubBlock {
    string label;
    vector<string> pins;
    string clock_pin;
};


template <typename A, typename B, typename C>
inline map<A, B> reverse_map(C &input) {
    map<A, B> r;
    typename C::iterator iter = input.begin();
    for(int i = 0; iter != input.end(); iter++, i++) {
        r[*iter] = i;
    }
    return r;
}


template <typename T>
class VprNetParser {
    void ragel_parse(std::istream &in_stream);
    vector<char> buf_vector;
    char* buf;
    int _BUFSIZE;

    const char *ls;
    const char *ts;
    const char *te;
    const char *be;
    const char *pin_start;
    const char *label_start;
    const char *subblock_label_start;

    int cs;
    int have;
    int length;
    string funcblocktype;
    string label;
    vector<string> pin_list;
    bool in_pin_list;

    string subblock_label;
    vector<SubBlock> subblocks;
    SubBlock *p_subblock;
    bool in_subblock_pin_list;
public:
    int net_index;
    int block_index;

    map<string, vector<string> > block_label_to_net_labels_;
    vector<map<string, vector<T> > > block_sub_blocks_;
    set<string> net_labels_;
    set<string> global_labels_;
    vector<vector<T> > block_used_pins_;
    vector<string> block_labels_;
    set<string> block_types_;
    vector<string> block_type_;

    T funcblock_count_;
    T input_count_;
    T output_count_;
    T global_count_;

    VprNetParser() : block_index(0), net_index(0), funcblock_count_(0),
                     input_count_(0), output_count_(0), global_count_(0) {
        buf_vector = vector<char>(DEF_BUFSIZE);
    }
    VprNetParser(int buffer_size) : block_index(0), net_index(0),
                                    funcblock_count_(0), input_count_(0),
                                    output_count_(0), global_count_(0)  {
        buf_vector = vector<char>(buffer_size);
    }

    void init();

    virtual void parse(std::istream &in_stream) {
        this->ragel_parse(in_stream);
    }

    virtual void process_funcblock() {
        funcblock_count_++;
        this->process_block();
    }

    virtual void process_input() {
        input_count_++;
        net_index++;
        this->process_block();
    }

    virtual void process_output() {
        output_count_++;
        block_index++;
        this->process_block();
    }

    virtual void process_global() {
        this->global_labels_.insert(label);
        global_count_++;
    }

    virtual void process_block() {
        vector<T> used_pins;
        for(int i = 0; i < pin_list.size(); i++) {
            if(pin_list[i] != "open") {
                this->block_label_to_net_labels_[label].push_back(pin_list[i]);
                this->net_labels_.insert(pin_list[i]);
                used_pins.push_back(i);
            }
        }
        block_labels_.push_back(label);
        this->block_used_pins_.push_back(used_pins);
        this->block_types_.insert(funcblocktype);
        this->block_type_.push_back(funcblocktype);
        map<string, vector<T> > sub_blocks;
        for(int i = 0; i < this->subblocks.size(); i++) {
            vector<T> used_pins;
            SubBlock const &sub_block = this->subblocks[i];
            for(int j = 0; j < sub_block.pins.size(); j++) {
                if(this->subblocks[i].pins[j] != "open") {
                    used_pins.push_back(j);
                }
            }
            if(sub_block.clock_pin != "open") {
                used_pins.push_back(sub_block.pins.size());
            }
            sub_blocks[sub_block.label] = used_pins;
        }
        this->block_sub_blocks_.push_back(sub_blocks);
        block_index++;
    }

    virtual void reset() {
        net_index = 0;
        block_index = 0;
        output_count_ = 0;
        input_count_ = 0;
        funcblock_count_ = 0;
        global_count_ = 0;
    }

    map<string, T> net_label_to_index() {
        return reverse_map<string, T>(this->net_labels_);
    }

    map<string, T> block_label_to_index() {
        return reverse_map<string, T>(this->block_labels_);
    }

    vector<vector<T> > block_to_net_ids(bool include_global=true) {
        map<string, vector<string> > &b2n_labels = this->block_label_to_net_labels_;
        map<string, T> net_label_to_index = this->net_label_to_index();

        vector<vector<T> > b2n_ids(this->block_labels_.size());

        vector<string>::iterator block_iter = this->block_labels_.begin();
        for(int i = 0; block_iter != this->block_labels_.end(); block_iter++,
                i++) {
            vector<string> &block_net_labels = b2n_labels[*block_iter];
            vector<string>::iterator block_net_iter = block_net_labels.begin();
            for(; block_net_iter != block_net_labels.end(); block_net_iter++) {
                string &net_label = *block_net_iter;
                /*
                 * Only include the net if it's not a global net, or if
                 * `include_global` is set to `true`.
                 */
                if(include_global ||
                   this->global_labels_.find(net_label) ==
                   this->global_labels_.end()) {
                    b2n_ids[i].push_back(net_label_to_index[net_label]);
                }
            }
        }
        return b2n_ids;
    }

    vector<vector<T> > net_to_block_ids(bool include_global=true) {
        vector<vector<T> > net2block_ids(this->net_labels_.size());
        map<string, vector<string> > &b2n_labels =
                this->block_label_to_net_labels_;
        map<string, vector<string> >::iterator block_nets_iter =
                b2n_labels.begin();
        map<string, T> block_label_to_index = this->block_label_to_index();
        map<string, T> net_label_to_index = this->net_label_to_index();

        for(int i = 0; block_nets_iter != b2n_labels.end();
                block_nets_iter++, i++) {
            vector<string> &block_net_labels = block_nets_iter->second;
            vector<string>::iterator block_net_iter = block_net_labels.begin();
            for(; block_net_iter != block_net_labels.end(); block_net_iter++) {
                int net_index = net_label_to_index[*block_net_iter];
                int block_index = block_label_to_index[block_nets_iter->first];
                /*
                 * Only process the net if it's not a global net, or if
                 * `include_global` is set to `true`.
                 */
                if(include_global ||
                   this->global_labels_.find(*block_net_iter) ==
                   this->global_labels_.end()) {
                    net2block_ids[net_index].push_back(block_index);
                }
            }
        }

        for(int i = 0; i < net2block_ids.size(); i++) {
            vector<T> &block_ids = net2block_ids[i];
            sort(block_ids.begin(), block_ids.end());
        }
        return net2block_ids;
    }

    map<string, vector<T> > block_ids_by_type() {
        map<string, vector<T> > b;
        set<string>::iterator block_types_iter = this->block_types_.begin();
        for(; block_types_iter != this->block_types_.end();
                block_types_iter++) {
            b[*block_types_iter] = vector<T>();
        }
        for(int i = 0; i < this->block_type_.size(); i++) {
            string &block_type = this->block_type_[i];
            b[block_type].push_back(i);
        }
        block_types_iter = this->block_types_.begin();
        for(; block_types_iter != this->block_types_.end();
                block_types_iter++) {
            string const &block_type = *block_types_iter;
            vector<T> &block_ids = b[block_type];
            sort(block_ids.begin(), block_ids.end());
        }
        return b;
    }
};


template <typename T>
class VprNetFileParser : public VprNetParser<T> {
public:
    string netlist_filepath_;
    using VprNetParser<T>::parse;

    VprNetFileParser(string input_filename) :
            VprNetParser<T>(), netlist_filepath_(input_filename) {}

    void parse() {
        this->reset();
        ifstream in_file(this->netlist_filepath_.c_str());
        this->parse(in_file);
        in_file.close();
    }
};
#endif
