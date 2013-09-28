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

        pin_class_map_t pin_class_map_
        pin_class_reverse_map_t pin_class_reverse_map_
        vector[string] net_labels_
        net_label_map_t net_label_map_
        block_label_map_t block_label_map_
        net_to_block_indexes_t net_to_block_indexes_
        block_to_net_indexes_t block_to_net_indexes_

        NetlistReader(string in_filename)
        void parse()
