#include "common_constants.hpp" // импор для namespace contains
#include "validation_type.hpp"  // для ValidationType
#include "sort_algorithm.hpp"
#pragma once

/*Статические методы - можно использовать без экзмепляра класса и не имеют доступа к this*/

/*Здесь хранятся только логика для проверки данных однмерных массивов*/

class ArrayProcessor
{
public:
    // проверка на валидность в зависимости от операции
    static bool valid_array_size(int size, ValidationType type_operation)
    {
        if (size > Constants::MAX_BUF)
        {
            return false;
        }
        switch (type_operation)
        {
        case ValidationType::FOR_SUM:
            if (size < 2)
            {
                return false;
            }
            break;
        case ValidationType::FOR_SORT:
            if (size < 1)
            {
                return false;
            }
            break;
        case ValidationType::FOR_PRODUCT: // для будущего использования
            if (size < 4)
            {
                // соответствующая ошибка
                return false;
            }
            break;
        }
        return true;
    }

    // ПРИМЕР ПЕРЕГРУЗКИ
    static bool valid_array_size(long int size, ValidationType type_operation)
    {
        if (size > Constants::MAX_BUF)
        {
            return false;
        }
        switch (type_operation)
        {
        case ValidationType::FOR_SUM:
            if (size < 2)
            {
                return false;
            }
            break;
        case ValidationType::FOR_SORT:
            if (size < 1)
            {
                return false;
            }
            break;
        case ValidationType::FOR_PRODUCT: // для будущего использования
            if (size < 4)
            {
                return false;
            }
            break;
        }
        return true;
    }

    // проверка на валидоность массива для суммы
    template <typename T>
    static bool valid_for_negative_sum(T *arr, int n)
    {
        if (arr == nullptr)
            return false;
        int negative_count = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < 0)
            {
                negative_count++;
            }
        }
        if (negative_count < 2)
        {
            return false;
        }
        return true;
    }

    // проверка массива на валидность для сортировки
    template <typename T>
    static bool valid_for_sort(T *arr)
    {
        if (arr == nullptr)
            return false;
        return true;
    }

    // проверка что массив не нулевой указатель перед анчалом выполнения работы для класса Data
    template <typename T>
    static bool valid_array_no_null(T *arr)
    {
        if (arr == nullptr)
        {
            return false;
        }
        return true;
    }

    // проверка что результат работы не нулевой указаетль для класса Aplication
    template <typename T>
    static bool valid_result_for_output_process_1(T *result_of_process_1)
    {
        return valid_array_no_null(result_of_process_1);
    }

    // функция проверки вхождения элемента в массив
    template <typename T>
    static bool in_arr(T *array, T elem, int size)
    {
        for (int i = 0; i < size; i++)
        {
            if (array[i] == elem)
            {
                return true;
            }
        }
        return false;
    }

    // фукнця проверки массива на валидность для поиска произведения между минимумом и максимумом
    template <typename T>
    static bool valid_for_product_min_max(T *arr, int n)
    {
        if (arr == nullptr)
            return false;
        int count_elements = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < 0)
            {
                count_elements++;
            }
        }
        if (count_elements < 4)
        {
            return false;
        }
        return true;
    }

    // фукнця проверки массива на валидность для поиска произведения между минимумом и максимумом
    static bool valid_index_for_product_min_max(int ind_max, int ind_min)
    {
        if (ind_max < ind_min)
        {
            return (ind_min - ind_max) >= 3;
        }
        if (ind_min < ind_max)
        {
            return (ind_max - ind_min) >= 3;
        }
        else
        {
            return false;
        }
    }

    // проверка на едиенственность минимума и максимума
    template <typename T>
    static bool valid_min_and_max_unique_for_sort_array(T *sorted_array, int size)
    {
        return not((sorted_array[0] == sorted_array[1]) || (sorted_array[size - 1] == sorted_array[size - 2]));
    }

    // проверка индекса
    template <typename T>
    static bool valid_ind_dimension(int ind, int n)
    {
        return (-1 < ind < n);
    }
};