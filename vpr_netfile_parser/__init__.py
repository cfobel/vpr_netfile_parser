import os


def get_includes():
    import vpr_netfile_parser
    """
    Return the directory that contains the vpr_netfile_parser Cython \\*.hpp
    and \\*.pxd header files.

    Extension modules that need to compile against vpr_netfile_parser should
    use this function to locate the appropriate include directory.

    Notes
    -----
    When using ``distutils``, for example in ``setup.py``.
    ::

        import vpr_netfile_parser
        ...
        Extension('extension_name', ...
                  include_dirs=[...] + vpr_netfile_parser.get_includes())
        ...

    """
    return [os.path.abspath(os.path.dirname(vpr_netfile_parser.__file__))]


def get_source_files():
    """
    Return the list of source files that must be compiled along with the
    headers returned by `get_includes()`.

    Extension modules that need to compile against vpr_netfile_parser should
    use this function to locate the appropriate source file paths based on the
    installed `vpr_netfile_parser` path.

    Notes
    -----
    When using ``distutils``, for example in ``setup.py``.
    ::

        import vpr_netfile_parser
        ...
        Extension('extension_name', [...] +
                                    vpr_netfile_parser.get_source_files(),
                  ...)
        ...

    """
    import vpr_netfile_parser

    return [os.path.abspath(os.path.join(os.path.dirname(vpr_netfile_parser
                                                         .__file__),
                                         'VprNetParser_ragel.cpp'))]
