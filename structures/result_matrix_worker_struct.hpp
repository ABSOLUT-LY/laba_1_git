#pragma once

struct ZeroFreeRowIndexes
{
    int *indexes;
    int count;
    ZeroFreeRowIndexes() : indexes(nullptr), count(0) {};
    ZeroFreeRowIndexes(int *inds, int c) : indexes(inds), count(c) {};
};

template <typename T>
struct MaxElemAndIndex
{
    int index_x;
    int index_y;
    T max_elem;
    MaxElemAndIndex() : index_x(0), index_y(0), max_elem(0) {};
};
