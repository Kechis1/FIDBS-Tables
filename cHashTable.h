//
// Created by Daniel Bill on 12/02/2020.
//

#ifndef FIDBS1_HEAPTABLE_H
#define FIDBS1_HEAPTABLE_H

#endif //FIDBS1_HEAPTABLE_H


#pragma once

#include "cHashTableNode.h"
#include "new"

template<class TKey, class TData>
class cHashTable {
private:
    int mSize;
    cHashTableNode<TKey, TData> **mHashTable;
    int mItemCount;
    int mNodeCount;
    cMemory *mMemory;

private:
    inline int HashValue(const TKey &key) const;

public :
    explicit cHashTable(int size);

    cHashTable(int size, cMemory *memory);

    ~cHashTable();

    bool Add(const TKey &key, const TData &data);

    bool Find(const TKey &key, TData &data) const;

    void PrintStat() const;
};

template<class TKey, class TData>
cHashTable<TKey, TData>::cHashTable(int size, cMemory *memory) {
    mSize = size;
    mHashTable = new cHashTableNode<TKey, TData> *[size];
    for (int i = 0; i < mSize; i++) {
        mHashTable[i] = NULL;
    }
    mMemory = memory;
    mNodeCount = 0;
    mItemCount = 0;
}

template<class TKey, class TData>
cHashTable<TKey, TData>::cHashTable(int size) {
    mSize = size;
    mHashTable = new cHashTableNode<TKey, TData> *[size];
    for (int i = 0; i < mSize; i++) {
        mHashTable[i] = NULL;
    }
    mNodeCount = 0;
    mItemCount = 0;
}

template<class TKey, class TData>
cHashTable<TKey, TData>::~cHashTable() {
    if (mMemory == NULL) {
        for (int i = 0; i < mSize; i++) {
            if (mHashTable[i] != NULL) {
                delete mHashTable[i];
            }
        }
    }
    delete mHashTable;
}

template<class TKey, class TData>
inline int cHashTable<TKey, TData>::HashValue(const TKey &key) const {
    return key % mSize;
}

/*template<class TKey, class TData>
bool cHashTable<TKey, TData>::Add(const TKey &key, const TData &data) {
    int hv = HashValue(key);
    if (mHashTable[hv] == NULL) {
        mHashTable[hv] = new cHashTableNode<TKey, TData>();
        mNodeCount++;
    }
    return mHashTable[hv]->Add(key, data, mItemCount, mNodeCount);
}*/

template<class TKey, class TData>
bool cHashTable<TKey, TData>::Add(const TKey &key, const TData &data) {
    int hv = HashValue(key);
    if (mHashTable[hv] == NULL) {
        if (mMemory == NULL) {
            mHashTable[hv] = new cHashTableNode<TKey, TData>();
        } else {
            char * mem = mMemory->New(sizeof(cHashTableNode<TKey, TData>));
            mHashTable[hv] = new (mem)cHashTableNode<TKey, TData>();
        }
        mNodeCount++;
    }
    return mHashTable[hv]->Add(key, data, mMemory, mItemCount, mNodeCount);
}

template<class TKey, class TData>
bool cHashTable<TKey, TData>::Find(const TKey &key, TData &data) const {
    int hv = HashValue(key);
    if (mHashTable[hv] == NULL) {
        return false;
    }
    return mHashTable[hv]->Find(key, data);
}

template<class TKey, class TData>
void cHashTable<TKey, TData>::PrintStat() const {
    printf("HashTable Statistics : Size : %i, ItemCount : %i, NodeCount : %i, Avg.Items / Slot : %.2f. \n", mSize,
           mItemCount, mNodeCount, (float) mItemCount / mSize);
}

