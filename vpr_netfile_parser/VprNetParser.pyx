#cython: embedsignature=False
from libcpp.vector cimport vector
from libcpp.map cimport map
from libcpp.string cimport string
from cython.operator cimport dereference as deref
from VprNetParser cimport VprNetFileParser

from collections import OrderedDict


ctypedef unsigned int uint


cdef class cSubBlock:
    cdef SubBlock *thisptr

    def __cinit__(self, size_t data_ptr):
        self.thisptr = <SubBlock *>data_ptr

    property label:
        def __get__(self):
            return self.thisptr.label

    property pins:
        def __get__(self):
            return [v for v in self.thisptr.pins]

    property clock_pin:
        def __get__(self):
            return self.thisptr.clock_pin

    def __str__(self):
        return u'[%s] clock_pin: %s, pins: %s' % (self.label, self.clock_pin,
                                                  self.pins)



cdef class cVprNetFileParser:
    cdef VprNetFileParser[uint] *thisptr
    cdef object _block_sub_blocks
    cdef object _net_labels
    cdef object _block_labels
    cdef object _global_labels
    cdef object _block_label_to_net_labels
    cdef object _block_label_to_index
    cdef object _net_label_to_index

    def __cinit__(self, netlist_path):
        cdef string in_file = netlist_path
        self.thisptr = new VprNetFileParser[uint](in_file)
        self.thisptr.init()
        self._parse()

    def _parse(self):
        self.thisptr.parse()
        # Cache data-structures to improve performance of property lookup.
        self._block_label_to_index = self.c_block_label_to_index()
        self._net_label_to_index = self.c_net_label_to_index()
        self._block_sub_blocks = self.thisptr.block_sub_blocks_
        self._net_labels = [v for v in self.thisptr.net_labels_]
        self._block_labels = [v for v in self.thisptr.block_labels_]
        self._global_labels = [v for v in self.thisptr.global_labels_]
        self._block_label_to_net_labels = OrderedDict([(k, v)
                for k, v in self.thisptr.block_label_to_net_labels_])

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
            return self._block_labels

    property block_type:
        def __get__(self):
            return self.thisptr.block_type_

    property block_types:
        def __get__(self):
            return self.thisptr.block_types_

    property block_label_to_net_labels:
        def __get__(self):
            return self._block_label_to_net_labels

    property net_label_to_index:
        def __get__(self):
            '''
            Return a mapping from each net-label to the corresponding net-index
            number.
            '''
            return self._net_label_to_index

    property block_label_to_index:
        def __get__(self):
            '''
            Return a mapping from each block-label to the corresponding block-index
            number.
            '''
            return self._block_label_to_index

    def block_to_net_ids(self, include_global=True):
        '''
        For each block, return the list of indexes for nets connected to the
        block _(in ascending order)_.

        __NB__ The lists for the blocks are sorted according to the order the
          blocks are listed in the input file _(i.e., the order of the labels
          in the `block_labels` list)_.
        '''
        b2n_labels = self.block_label_to_net_labels
        return [[self.net_label_to_index[n]
                 for n in b2n_labels[block_label]
                 if include_global or (n not in self.global_labels)]
                for i, block_label in enumerate(self.block_labels)]

    def net_to_block_ids(self, include_global=True):
        '''
        def net_to_block_ids(self, include_global=True)

        For each net, return the list of indexes for blocks connected to the
        net _(in ascending order)_.

        __NB__ The lists for the nets are sorted according to alphabetical
          net-label order.
        '''
        net_to_block_indexes = OrderedDict()
        for i, block_net_ids in enumerate(self.block_to_net_ids(include_global)):
            for net_id in block_net_ids:
                net_block_ids = net_to_block_indexes.setdefault(net_id, [])
                net_block_ids.append(i)
        return list(zip(*sorted(net_to_block_indexes.items()))[1])

    def block_ids_by_type(self):
        block_ids_by_type = OrderedDict([(k, []) for k in self.block_types])
        for block_id, block_type in enumerate(self.block_type):
            block_ids_by_type[block_type].append(block_id)
        return block_ids_by_type

    def c_net_to_block_ids(self, include_global=True):
        return self.thisptr.net_to_block_ids(include_global)

    def c_block_to_net_ids(self, include_global=True):
        return self.thisptr.block_to_net_ids(include_global)

    def c_net_label_to_index(self):
        return self.thisptr.net_label_to_index()

    def c_block_label_to_index(self):
        return self.thisptr.block_label_to_index()

    def c_block_ids_by_type(self):
        return self.thisptr.block_ids_by_type()
