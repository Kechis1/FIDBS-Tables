//
// Created by Daniel Bill on 12/02/2020.
//

#ifndef FIDBS1_HEAPTABLE_H
#define FIDBS1_HEAPTABLE_H

#endif //FIDBS1_HEAPTABLE_H


#pragma once

#include <cassert>
#include <cstdlib>

template<class TKey, class TData>
class cHeapTable {
private:
    int mCapacity;
    int mCount;
    char *mData;
    int const mRowSize = sizeof(TKey) + sizeof(TData);

private:
    inline char *GetRowPointer(int rowId) const;

public:
    explicit cHeapTable(int capacity);
    ~cHeapTable();

    bool Add(const TKey &key, const TData &data);

    bool Get(int rowId, TKey &key, TData &data) const;

    bool Find(const TKey &key, TData &data) const;
};

template<class TKey, class TData>
cHeapTable<TKey, TData>::cHeapTable(int capacity) {
    mCapacity = capacity;
    mCount = 0;
    mData = new char[mRowSize * capacity];
}

template<class TKey, class TData>
cHeapTable<TKey, TData>::~cHeapTable() {
    if (mData != NULL) {
        delete mData;
        mData = NULL;
        mCapacity = 0;
        mCount = 0;
    }
}

template<class TKey, class TData>
inline char *cHeapTable<TKey, TData>::GetRowPointer(int rowId) const {
    return mData + rowId * mRowSize;
}

template<class TKey, class TData>
bool cHeapTable<TKey, TData>::Get(int rowId, TKey &key, TData &data) const {
    bool ret = false;
    assert(rowId >= 0 && rowId < mCount);
    ret = true;

    char *p = GetRowPointer(rowId);
    key = *((TKey *) p);
    data = *((TData *) (p + sizeof(TKey)));

    return ret;
}

template<class TKey, class TData>
bool cHeapTable<TKey, TData>::Add(const TKey &key, const TData &data) {
    char *p = GetRowPointer(mCount);
    *((int *) p) = key;
    *((int *) (p + sizeof(TKey))) = data;
    mCount++;
    return true;
}

template<class TKey, class TData>
bool cHeapTable<TKey, TData>::Find(const TKey &key, TData &data) const {
    for (int i = 0; i < mCount; i++) {
        char *p = GetRowPointer(i);
        if (*((int *) p) == key) {
            data = *((TData *) (p + sizeof(TKey)));
            return true;
        }
    }
    return false;
}