from nose.tools import eq_
from VprNetlistReader import cVprNetFileParser


def test_block_to_net_ids():
    r = cVprNetFileParser('/var/benchmarks/mcnc/tseng.net')

    # Verify that when we convert back from the integer-mapping of
    # block-indexes to the corresponding net-indexes, we get the original
    # block-label to net-label mapping.
    eq_(sorted(r.block_label_to_net_labels.items()),
        sorted([(r.block_labels[i], [r.net_labels[n]
                                     for n in net_ids])
                for i, net_ids in enumerate(r.block_to_net_ids())]))


def test_net_to_block_ids():
    r = cVprNetFileParser('/var/benchmarks/mcnc/tseng.net')

    block_to_net_ids = r.block_to_net_ids()

    for net_id, block_ids in enumerate(r.net_to_block_ids()):
        for b in block_ids:
            assert(net_id in block_to_net_ids[b])


def test_c_block_to_net_ids():
    r = cVprNetFileParser('/var/benchmarks/mcnc/tseng.net')

    # Verify that when we convert back from the integer-mapping of
    # block-indexes to the corresponding net-indexes, we get the original
    # block-label to net-label mapping.
    eq_(sorted(r.block_label_to_net_labels.items()),
        sorted([(r.block_labels[i], [r.net_labels[n]
                                     for n in net_ids])
                for i, net_ids in enumerate(r.c_block_to_net_ids())]))


def test_c_net_to_block_ids():
    r = cVprNetFileParser('/var/benchmarks/mcnc/tseng.net')

    block_to_net_ids = r.c_block_to_net_ids()

    for net_id, block_ids in enumerate(r.c_net_to_block_ids()):
        for b in block_ids:
            assert(net_id in block_to_net_ids[b])

    eq_(block_to_net_ids, r.block_to_net_ids())
