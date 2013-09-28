from libcpp.vector cimport vector
from libcpp.map cimport map
from libcpp.string cimport string
from cython.operator cimport dereference as deref
from VprNetlistReader cimport VprNetFileParser


cdef class cVprNetFileParser:
    cdef VprNetFileParser *thisptr

    def __cinit__(self, netlist_path):
        cdef string in_file = netlist_path
        self.thisptr = new VprNetFileParser(in_file)
        self.thisptr.init()
        self._parse()

    def _parse(self):
        self.thisptr.parse()

    property net_labels:
        def __get__(self):
            return [v for v in self.thisptr.net_labels_]

    property global_labels:
        def __get__(self):
            return [v for v in self.thisptr.global_labels_]

    property block_used_pins:
        def __get__(self):
            return self.thisptr.block_used_pins_

    property block_labels:
        def __get__(self):
            return self.thisptr.block_labels_

    property block_type:
        def __get__(self):
            return self.thisptr.block_type_

    property block_types:
        def __get__(self):
            return self.thisptr.block_types_

    property block_label_to_net_labels:
        def __get__(self):
            return self.thisptr.block_label_to_net_labels_
