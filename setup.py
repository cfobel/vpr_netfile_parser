#!/usr/bin/env python
import os
import sys
sys.path.insert(0, '.')
from distutils.core import setup, Extension
from Cython.Build import cythonize

import vpr_netfile_parser
import version

include_dirs = vpr_netfile_parser.get_includes()
sys.path += include_dirs

cc_config = dict(include_dirs=include_dirs, language='c++',
                 extra_compile_args=['-O3', '-std=c++0x', '-Wfatal-errors'])


cython_exts = [Extension('vpr_netfile_parser.VprNetParser',
                          ['vpr_netfile_parser/VprNetParser.pyx',
                           'vpr_netfile_parser/VprNetParser_ragel.cpp'],
                         **cc_config)]


setup(name = "vpr_netfile_parser",
      version=version.getVersion(),
      description = "C++ VPR `.net` netlist-file parser, with Cython bindings",
      keywords = "fpga placement python C++ cython vpr",
      author = "Christian Fobel",
      url = "https://github.com/cfobel/vpr_netfile_parser",
      license = "GPL",
      long_description = """""",
      packages = ['vpr_netfile_parser'],
      package_data={'vpr_netfile_parser': ['VprNetParser.hpp']},
      ext_modules=cythonize(cython_exts))
