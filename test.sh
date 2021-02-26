#!/bin/bash
verilator -Wall -cc FSM.v --exe simulate.cpp
cd obj_dir && make -j -f VFSM.mk
./VFSM