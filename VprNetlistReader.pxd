from libcpp.vector cimport vector
from libcpp.map cimport map
from libcpp.set cimport set as c_set
from libcpp.string cimport string


cdef extern from "VprNetParser.hpp":
    cdef struct SubBlock:
        string label
        vector[string] pins
        string clock_pin


    cdef cppclass VprNetFileParser[T]:
        T funcblock_count
        T input_count
        T output_count
        T global_count

        map[string, vector[string]] block_label_to_net_labels_
        c_set[string] net_labels_
        c_set[string] global_labels_
        vector[map[string, vector[T]]] block_sub_blocks_
        vector[vector[T]] block_used_pins_
        vector[string] block_labels_
        vector[string] block_type_
        c_set[string] block_types_
        vector[vector[T]] net_to_block_ids(bint include_global)
        vector[vector[T]] block_to_net_ids(bint include_global)
        map[string, T] net_label_to_index()
        map[string, T] block_label_to_index()
        map[string, vector[T]] block_ids_by_type()

        VprNetFileParser(string in_filename)
        void init()
        void parse()
