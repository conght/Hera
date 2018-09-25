# Hera 

[![License](https://img.shields.io/github/license/mashape/apistatus.svg)](LICENSE)
[![Build Status](https://travis-ci.org/XiaoMi/mace.svg?branch=master)](https://travis-ci.org/XiaoMi/mace)
[![doc build status](https://readthedocs.org/projects/mace/badge/?version=latest)](https://readthedocs.org/projects/mace/badge/?version=latest)

[Hera 中文手册](README_CN.md)

An awesome common lib for C++, implemented by using CPP template.

### How to install

 Including the header files of Hera directly. No need to compile & install.

### Document

- [Clock](include/clock.hpp)

    Providing a way to get the current timestamp which supported various accuracy levels ;

    Class ProgressTimer could statistic time periods.
    
- [Noncopyable](include/noncopyable.hpp)

    Inheriting class noncopyable, subclass can get the ability of not being copied.

- [Singleton](include/singleton.hpp)

    Hera provides a thread safe single instance pattern template class;

    Inheriting class Singleton, subclasses can be turned into singleton mode.

- [String_Util](include/string_util.hpp)

    Providing basic string tools.

- Logger

    TODO
    
- Lock

    TODO

- Share Memory Tools

    TODO

- FIFO tools

    TODO

- Configure tools

    TODO    
