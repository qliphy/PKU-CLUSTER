#!/bin/bash
g++ -o run `root-config --cflags --glibs` runxx.C
./run >> run.txt 	
