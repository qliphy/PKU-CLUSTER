#!/bin/bash
 g++ -o run `root-config --cflags --glibs` sigmaieie.C 
./run >> process_run.txt
