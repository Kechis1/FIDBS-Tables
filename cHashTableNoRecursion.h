//
// Created by Daniel Bill on 26/02/2020.
//

#ifndef FIDBS1_CHASHTABLENORECURSION_H
#define FIDBS1_CHASHTABLENORECURSION_H

#endif //FIDBS1_CHASHTABLENORECURSION_H

#pragma once

#include "cHashTableNodeNoRecursion.h"
#include "new"


template<class TKey, class TData>
class cHashTableNoRecursion {
private:
    int mSize;
    cHashTableNodeNoRecursion<TKey, TData> **mHashTable;
    int mItemCount;
    int mNodeCount;
    cMemory *mMemory;

private:
    inline int HashValue(const TKey &key) const;

public:
    cHashTableNoRecursion(int size, cMemory *memory);

    ~cHashTableNoRecursion();

    bool Add(const TKey &key, const TData &data);

    bool Find(const TKey &key, TData &data) const;

    void PrintStat() const;
};

template<class TKey, class TData>
cHashTableNoRecursion<TKey, TData>::cHashTableNoRecursion(int size, cMemory *memory) {
    mSize = size;
    mHashTable = new cHashTableNodeNoRecursion<TKey, TData> *[size];
    for (int i = 0; i < mSize; i++) {
        mHashTable[i] = NULL;
    }
    mMemory = memory;
    mNodeCount = 0;
    mItemCount = 0;
}

template<class TKey, class TData>
cHashTableNoRecursion<TKey, TData>::~cHashTableNoRecursion() {
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
bool cHashTableNoRecursion<TKey, TData>::Add(const TKey &key, const TData &data) {
    int hv = HashValue(key);

    if (mHashTable[hv] == nullptr) {
        if (mMemory == nullptr) {
            cHashTableNodeNoRecursion<TKey, TData> *prev = NULL;
            cHashTableNodeNoRecursion<TKey, TData> *entry = mHashTable[hv];

            while (entry != NULL) {
                prev = entry;
                entry = entry->mNextNode;
            }

            entry = new cHashTableNodeNoRecursion<TKey, TData>(key, data);
            if (prev == NULL) {
                mHashTable[hv] = entry;
            } else {
                prev->mNextNode = entry;
            }
        } else {
            char *mem = mMemory->New(sizeof(cHashTableNodeNoRecursion<TKey, TData>));

            cHashTableNodeNoRecursion<TKey, TData> *prev = NULL;
            cHashTableNodeNoRecursion<TKey, TData> *entry = mHashTable[hv];

            while (entry != NULL) {
                prev = entry;
                entry = entry->mNextNode;
            }

            entry = new(mem)cHashTableNodeNoRecursion<TKey, TData>(key, data);
            if (prev == NULL) {
                mHashTable[hv] = entry;
            } else {
                prev->mNextNode = entry;
            }
        }
    }
    return true;
}

template<class TKey, class TData>
bool cHashTableNoRecursion<TKey, TData>::Find(const TKey &key, TData &data) const {
    bool found = false;
    int hv = HashValue(key);

    if (mHashTable[hv] == nullptr) {
        return false;
    }

    cHashTableNodeNoRecursion<TKey, TData> *entry = mHashTable[hv];

    while (entry != NULL) {
        if (entry->mKey == key) {
            found = true;
        }
        entry = entry->mNextNode;
    }

    return found;
}

template<class TKey, class TData>
inline int cHashTableNoRecursion<TKey, TData>::HashValue(const TKey &key) const {
    return key % mSize;
}

template<class TKey, class TData>
void cHashTableNoRecursion<TKey, TData>::PrintStat() const {
    printf("HashTable Statistics: Size: %d, ItemCount: %d, NodeCount: %d, Avg. Items/Slot: %.2f.\n",
           mSize, mItemCount, mNodeCount, (float) mItemCount / mSize);
}