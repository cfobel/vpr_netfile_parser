from libcpp.vector cimport vector
from libcpp.map cimport map
from libcpp.string cimport string
from cython.operator cimport dereference as deref
from VprNetlistReader cimport VprNetFileParser

from collections import OrderedDict


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
        self._net_labels = [v for v in self.thisptr.net_labels_]
        self._global_labels = [v for v in self.thisptr.global_labels_]

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
            return OrderedDict([(k, v) for k, v in  self.thisptr.block_label_to_net_labels_])

    def net_label_to_index(self):
        return OrderedDict([(v, i) for i, v in enumerate(self.net_labels)])

    def block_label_to_index(self):
        return OrderedDict([(v, i) for i, v in enumerate(self.block_labels)])

    def block_to_net_ids(self, include_global=True):
        b2n_labels = self.block_label_to_net_labels
        net_label_to_index = self.net_label_to_index()
        return [[net_label_to_index[n]
                 for n in b2n_labels[block_label]
                 if include_global or (n not in self.global_labels)]
                for i, block_label in enumerate(self.block_labels)]

    def net_to_block_ids(self, include_global=True):
        net_to_block_indexes = OrderedDict()
        for i, block_net_ids in enumerate(self.block_to_net_ids(include_global)):
            for net_id in block_net_ids:
                net_block_ids = net_to_block_indexes.setdefault(net_id, [])
                net_block_ids.append(i)
        return zip(*sorted(net_to_block_indexes.items()))[1]

    def block_ids_by_type(self):
        block_ids_by_type = OrderedDict([(k, []) for k in self.block_types])
        for block_id, block_type in enumerate(self.block_type):
            block_ids_by_type[block_type].append(block_id)
        return block_ids_by_type
