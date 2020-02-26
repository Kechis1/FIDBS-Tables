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
    cHashTableNodeNoRecursion<TKey, TData> * item = mHashTable[hv];
    bool ret = false;

    if (item == nullptr) {
        if (mMemory == nullptr) {
            item = new cHashTableNodeNoRecursion<TKey, TData>();
        } else {
            char * mem = mMemory->New(sizeof(cHashTableNodeNoRecursion<TKey, TData>));
            item = new(mem)cHashTableNodeNoRecursion<TKey, TData>();
        }
        mHashTable[hv] = item;
        mNodeCount++;
    }

    while (!item->mEmptyNode) {
        if (item->mKey == key) {
            ret = false;
        } else {
            if (item->mNextNode == nullptr) {
                if (mMemory == nullptr) {
                    item->mNextNode = new cHashTableNodeNoRecursion<TKey, TData>();
                } else {
                    char * mem = mMemory->New(sizeof(cHashTableNodeNoRecursion<TKey, TData>));
                    item->mNextNode = new (mem) cHashTableNodeNoRecursion<TKey, TData>();
                }
                mNodeCount++;
                item = item->mNextNode;
            }
        }
    }

    if (item->mEmptyNode) {
        item->mKey = key;
        item->mData = data;
        item->mEmptyNode = false;
        mItemCount++;
        ret = true;
    }
    return ret;
}

template<class TKey, class TData>
bool cHashTableNoRecursion<TKey, TData>::Find(const TKey &key, TData &data) const {
    int hv = HashValue(key);
    cHashTableNodeNoRecursion<TKey, TData> *item = mHashTable[hv];

    if (item == nullptr) {
        return false;
    }

    while (item != nullptr) {
        if (item->mKey == key) {
            data = item->mData;
            return true;
        } else {
            if (item->mNextNode == nullptr) return false;
            item = item->mNextNode;
        }
    }

    return false;
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