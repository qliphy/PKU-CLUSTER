#!/bin/bash
g++ -o runA `root-config --cflags --glibs` runxx.C
./runA	
