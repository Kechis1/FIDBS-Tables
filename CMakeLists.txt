cmake_minimum_required(VERSION 3.15)
project(fidbs1)

set(CMAKE_CXX_STANDARD 14)

add_executable(fidbs1 main.cpp cHeapTable.h cHeapTable_obj.h cRecord.h cHashTableNode.h cMemory.h cMemory.cpp cHashTableNodeNoRecursion.h cHashTableNoRecursion.h)