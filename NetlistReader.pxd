from libcpp.vector cimport vector
from libcpp.map cimport map
from libcpp.set cimport set
from libcpp.string cimport string


cdef enum PinClass:
   PIN_IN
   PIN_OUT
   PIN_GLOBAL

ctypedef map[PinClass, set[int] ] pin_class_map_t
ctypedef map[int, PinClass] pin_class_reverse_map_t
ctypedef map[string, int] net_label_map_t
ctypedef map[string, int] block_label_map_t
ctypedef vector[vector[int] ] net_to_block_indexes_t
ctypedef vector[vector[int] ] block_to_net_indexes_t


cdef extern from "NetlistReader.hpp":
    cdef cppclass NetlistReader:
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
        vector[string] block_types_

        NetlistReader(string in_filename)
        void parse()
