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

enum BlockType { BLOCK_INPUT, BLOCK_OUTPUT, BLOCK_GLOBAL };

typedef map<string, vector<string> > BlockLabelToNetLabels;


class NetlistReader {
public:
    VPRNetParser p;
    ifstream *in_stream;

    BlockLabelToNetLabels block_label_to_net_labels_;
    set<string> net_labels_;
    set<string> global_labels_;
    vector<vector<int> > block_used_pins_;
    vector<string> block_labels_;
    vector<string> block_types_;
    int funcblock_count;
    int input_count;
    int output_count;
    int global_count;

    int net_count;
    int block_count;

    int net_index;
    int block_index;

    NetlistReader(string input_filename) :
            net_index(0), block_index(0),
            funcblock_count(0), input_count(0),
            output_count(0), global_count(0) {
        this->in_stream = new ifstream(input_filename.c_str());
        p = VPRNetParser(32 << 10);
    }

    void reset() {
        net_index = 0;
        block_index = 0;
    }

    void rewind() {
        reset();
        in_stream->clear();
        in_stream->seekg(0, ios::beg);
    }

    /* Count pass: START */
    void process_funcblock(const string &funcblocktype,
            const string &label, const vector<string> &pins,
            const vector<SubBlock> &subblocks) {
        this->block_types_.push_back(funcblocktype);
        funcblock_count++;
        this->process_block(label, pins);
    }

    void process_input(const string &label, const vector<string> &pins) {
        this->block_types_.push_back("input");
        input_count++;
        net_index++;
        process_block(label, pins);
    }

    void process_output(const string &label, const vector<string> &pins) {
        this->block_types_.push_back("output");
        output_count++;
        block_index++;
        process_block(label, pins);
    }

    void process_global(const string &label) {
        this->global_labels_.insert(label);
        global_count++;
    }

    void process_block(const string &label, const vector<string> &pins) {
        vector<int> used_pins;
        for(int i = 0; i < pins.size(); i++) {
            if(pins[i] != "open") {
                this->block_label_to_net_labels_[label].push_back(pins[i]);
                this->net_labels_.insert(pins[i]);
                used_pins.push_back(i);
            }
        }
        block_labels_.push_back(label);
        this->block_used_pins_.push_back(used_pins);
        block_index++;
    }
    /* Count pass: END */

    //vpr::NetList parse() {
    void parse() {
        rewind();
        p.init();
        p.register_input_process_func(boost::bind(&NetlistReader::process_input, this, _1, _2));
        p.register_output_process_func(boost::bind(&NetlistReader::process_output, this, _1, _2));
        p.register_funcblock_process_func(boost::bind(&NetlistReader::process_funcblock, this, _1, _2, _3, _4));
        p.register_global_process_func(boost::bind(&NetlistReader::process_global, this, _1));
        p.parse(*in_stream);
        net_count = net_index;
        block_count = block_index;
    }

    ~NetlistReader() {
        this->in_stream->close();
    }
};


#endif
