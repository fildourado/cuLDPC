#!/bin/sh

#rm -rf build
mkdir -p build
cd build
#cmake --debug-output ..
#cmake --trace-expand ..
#cmake -DCMAKE_VERBOSE_MAKEFILE:BOOL=ON ..
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
make install
