#!/bin/bash
# $Id: beautify.bash 34 2007-04-24 13:21:06Z makhtar $
# Indent source files and generate tag files
astyle *.{h,hpp,cpp}
ebrowse *.{h,hpp,cpp}
etags *.{h,hpp,cpp}

cd qirdasend; astyle *.cpp
cd ../qirdarcv; astyle *.cpp
exit
