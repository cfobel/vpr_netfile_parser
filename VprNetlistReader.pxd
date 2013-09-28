from libcpp.vector cimport vector
from libcpp.map cimport map
from libcpp.set cimport set
from libcpp.string cimport string


cdef extern from "VprNetParser.hpp":
    cdef cppclass VprNetFileParser:
        int funcblock_count
        int input_count
        int output_count
        int global_count

        int net_count
        int block_count

        int net_index
        int block_index

        map[string, vector[string]] block_label_to_net_labels_
        set[string] net_labels_
        set[string] global_labels_
        vector[vector[int]] block_used_pins_
        vector[string] block_labels_
        vector[string] block_type_
        set[string] block_types_

        VprNetFileParser(string in_filename)
        void init()
        void parse()
