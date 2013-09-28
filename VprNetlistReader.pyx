from libcpp.vector cimport vector
from libcpp.map cimport map
from libcpp.string cimport string
from cython.operator cimport dereference as deref
from VprNetlistReader cimport VprNetFileParser


cdef class cSubBlock:
    cdef SubBlock *thisptr

    def __cinit__(self, size_t data_ptr):
        self.thisptr = <SubBlock *>data_ptr

    property label:
        def __get__(self):
            return self.thisptr.label

    property pins:
        def __get__(self):
            return self.thisptr.pins

    property clock_pin:
        def __get__(self):
            return self.thisptr.clock_pin

    def __str__(self):
        return u'[%s] clock_pin: %s, pins: %s' % (self.label, self.clock_pin,
                                                  self.pins)



cdef class cVprNetFileParser:
    cdef VprNetFileParser *thisptr
    cdef object _block_sub_blocks
    cdef object _net_labels
    cdef object _global_labels

    def __cinit__(self, netlist_path):
        cdef string in_file = netlist_path
        self.thisptr = new VprNetFileParser(in_file)
        self.thisptr.init()
        self._parse()

    def _parse(self):
        self.thisptr.parse()
        # Cache block-sub-blocks map to improve performance of
        # `block_sub_blocks` property lookup.
        self._block_sub_blocks = self.thisptr.block_sub_blocks_
        self._net_labels = set([v for v in self.thisptr.net_labels_])
        self._global_labels = set([v for v in self.thisptr.global_labels_])

    property block_sub_blocks:
        def __get__(self):
            return self._block_sub_blocks

    property net_labels:
        def __get__(self):
            return self._net_labels

    property global_labels:
        def __get__(self):
            return self._global_labels

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
