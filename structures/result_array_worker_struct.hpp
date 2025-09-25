#pragma once

template <typename T>
struct Arr_and_size
{
    T *arr;
    int size;
    Arr_and_size() : arr(nullptr), size(0) {};
    Arr_and_size(T *array, int n) : arr(array), size(n) {};
};
