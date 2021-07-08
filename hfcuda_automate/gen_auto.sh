#!/bin/bash
source env/bin/activate
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/lib64/clang-private python gen.py
deactivate
