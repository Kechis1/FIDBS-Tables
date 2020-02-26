//
// Created by Daniel Bill on 12/02/2020.
//

#ifndef FIDBS1_CHEAPTABLE_OBJ_H
#define FIDBS1_CHEAPTABLE_OBJ_H

#endif //FIDBS1_CHEAPTABLE_OBJ_H


#pragma once

#include <cassert>
#include <cstdlib>
#include "cRecord.h"

template<class TKey, class TData>
class cHeapTable_obj {
private:
    int mCapacity;
    int mCount;
    cRecord **mData;
    int const mRowSize = sizeof(TKey) + sizeof(TData);

public:
    explicit cHeapTable_obj(int capacity);
    ~cHeapTable_obj();

    bool Add(const TKey &key, const TData &data);
    bool Get(int rowId, TKey &key, TData &data) const;
    bool Find(const TKey &key, TData &data) const;
};

template<class TKey, class TData>
cHeapTable_obj<TKey, TData>::cHeapTable_obj(int capacity) {
    mCapacity = capacity;
    mCount = 0;
    mData = new cRecord * [capacity];
}

template<class TKey, class TData>
cHeapTable_obj<TKey, TData>::~cHeapTable_obj() {
    if (mData != NULL) {
        delete mData;
        mData = NULL;
        mCapacity = 0;
        mCount = 0;
    }
}

template<class TKey, class TData>
bool cHeapTable_obj<TKey, TData>::Get(int rowId, TKey &key, TData &data) const {
    assert(rowId >= 0 && rowId < mCount);
    key = mData[rowId]->mKey;
    data = mData[rowId]->mData;
    return true;
}

template<class TKey, class TData>
bool cHeapTable_obj<TKey, TData>::Add(const TKey &key, const TData &data) {
    mData[mCount] = new cRecord;
    mData[mCount]->mKey = key;
    mData[mCount]->mData = data;
    mCount++;
    return true;
}

template<class TKey, class TData>
bool cHeapTable_obj<TKey, TData>::Find(const TKey &key, TData &data) const {
    for (int i = 0; i < mCount; i++) {
        if (mData[i]->mKey == key) {
            data = mData[i]->mData;
            return true;
        }
    }
    return false;
}