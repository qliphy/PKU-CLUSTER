#!/bin/bash
g++ -o run `root-config --cflags --glibs` trans_fsr.C
./run >> process_run.txt
