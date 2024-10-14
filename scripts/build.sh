#!/bin/sh

rm -rf build
mkdir build
cd build
#cmake --debug-output ..
#cmake --trace-expand ..
#cmake -DCMAKE_VERBOSE_MAKEFILE:BOOL=ON ..
cmake ..
make
make install
