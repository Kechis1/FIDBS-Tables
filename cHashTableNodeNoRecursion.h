//
// Created by Daniel Bill on 26/02/2020.
//

#ifndef FIDBS1_CHASHTABLENODENORECURSION_H
#define FIDBS1_CHASHTABLENODENORECURSION_H

#endif //FIDBS1_CHASHTABLENIDENORECURSION_H

#pragma once

#include "cHashTableNode.h"
#include "cMemory.h"

template<class TKey, class TData>
class cHashTableNodeNoRecursion
{
public:
    cHashTableNodeNoRecursion* mNextNode;
    TKey mKey;
    TData mData;
    bool mEmptyNode;

    explicit cHashTableNodeNoRecursion(const TKey& mKey, TData& mData);
    cHashTableNodeNoRecursion();
    ~cHashTableNodeNoRecursion();
};

template<class TKey, class TData>
cHashTableNodeNoRecursion<TKey, TData>::cHashTableNodeNoRecursion(const TKey& mKey, TData& mData)
{
    this->mKey = mKey;
    this->mData = mData;
    mNextNode = nullptr;
    mEmptyNode = true;
}
template<class TKey, class TData>
cHashTableNodeNoRecursion<TKey, TData>::cHashTableNodeNoRecursion()
{
    mNextNode = nullptr;
    mEmptyNode = true;
}

template<class TKey, class TData>
cHashTableNodeNoRecursion<TKey, TData>::~cHashTableNodeNoRecursion() {
    if (mNextNode != NULL) {
        delete mNextNode;
        mNextNode = NULL;
    }
}