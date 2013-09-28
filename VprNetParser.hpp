#ifndef ___VPR_NET_PARSER__HPP___
#define ___VPR_NET_PARSER__HPP___

#include <fstream>
#include <iostream>
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
    vector<map<string, vector<int> > > block_sub_blocks_;
    set<string> net_labels_;
    set<string> global_labels_;
    vector<vector<int> > block_used_pins_;
    vector<string> block_labels_;
    set<string> block_types_;
    vector<string> block_type_;

    int funcblock_count_;
    int input_count_;
    int output_count_;
    int global_count_;

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
        vector<int> used_pins;
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
        map<string, vector<int> > sub_blocks;
        for(int i = 0; i < this->subblocks.size(); i++) {
            vector<int> used_pins;
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

};


class VprNetFileParser : public VprNetParser {
public:
    string netlist_filepath_;
    using VprNetParser::parse;

    VprNetFileParser(string input_filename) :
            VprNetParser(), netlist_filepath_(input_filename) {}

    void parse() {
        this->reset();
        ifstream in_file(this->netlist_filepath_.c_str());
        this->parse(in_file);
        in_file.close();
    }
};
#endif
