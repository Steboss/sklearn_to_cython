#!/bin/bash

rm -rf build nnet nnet.c  nnet.cpython-36m-x86_64-linux-gnu.so
python setup.py build_ext --inplace
cp nnet/* .
python tester.py
