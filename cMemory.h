//
// Created by bil0104 on 18.02.2020.
//

#ifndef FIDBS1_CMEMORY_H
#define FIDBS1_CMEMORY_H

#endif //FIDBS1_CMEMORY_H

#pragma once

#include <stdio.h>

class cMemory {
private:
    int mCapacity;
    int mSize;
    char *mData;
public:
    cMemory(int capacity);

    ~cMemory();

    inline char * New(int size);

    void PrintStat() const;
};

char *cMemory::New(int size) {
    char *mem = nullptr;
    if (mSize + size >= mCapacity) {
        printf("CriticalError : cMemory::New() : There is no memory. \n");
        mem = nullptr;
    } else {
        mem = mData + mSize;
        mSize += size;
    }
    return mem;
}