#!/bin/bash
wget -P /tmp https://github.com/masiya123/alx-low_level_programming/tree/master/0x18-dynamic_libraries/libhack.so
export LD_PRELOAD=/tmp/libhack.so
