#!/bin/bash

rm memory_hierarchy
g++ -std=c++17 -DLRU -DWRITE_BACK main.cpp processor.cpp cache.cpp memory.cpp -o memory_hierarchy
./memory_hierarchy
g++ -std=c++17 -DFIFO -DWRITE_BACK main.cpp processor.cpp cache.cpp memory.cpp -o memory_hierarchy
./memory_hierarchy
g++ -std=c++17 -DLRU -DWRITE_THROUGH main.cpp processor.cpp cache.cpp memory.cpp -o memory_hierarchy
./memory_hierarchy
g++ -std=c++17 -DFIFO -DWRITE_THROUGH main.cpp processor.cpp cache.cpp memory.cpp -o memory_hierarchy
./memory_hierarchy
