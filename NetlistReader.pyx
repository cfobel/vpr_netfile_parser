from libcpp.vector cimport vector
from libcpp.map cimport map
from libcpp.string cimport string
from cython.operator cimport dereference as deref


cdef class cNetlistReader:
    cdef NetlistReader *thisptr

    def __cinit__(self, netlist_path):
        cdef string in_file = netlist_path
        self.thisptr = new NetlistReader(in_file)

    def parse(self):
        self.thisptr.parse()

    property funcblock_count:
        def __get__(self):
            return self.thisptr.funcblock_count

    property input_count:
        def __get__(self):
            return self.thisptr.input_count

    property output_count:
        def __get__(self):
            return self.thisptr.output_count

    property global_count:
        def __get__(self):
            return self.thisptr.global_count

    property net_count:
        def __get__(self):
            return self.thisptr.net_count

    property block_count:
        def __get__(self):
            return self.thisptr.block_count

    property net_index:
        def __get__(self):
            return self.thisptr.net_index

    property block_index:
        def __get__(self):
            return self.thisptr.block_index

    property net_labels:
        def __get__(self):
            return self.thisptr.net_labels_

    property net_label_map:
        def __get__(self):
            return self.thisptr.net_label_map_

    property block_label_map:
        def __get__(self):
            return self.thisptr.block_label_map_

    property net_to_block_indexes:
        def __get__(self):
            return self.thisptr.net_to_block_indexes_

    property block_to_net_indexes:
        def __get__(self):
            return self.thisptr.block_to_net_indexes_

