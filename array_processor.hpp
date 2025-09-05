#include "common_constants.hpp" // импор для namespace contains
#include "console_ui.hpp"
#pragma once

/*Статические методы - можно использовать без экзмепляра класса и не имеют доступа к this*/

/*Здесь хранятся только логика для проверки данных*/

class ArrayProcessor
{
public:
    // проверка на валидность для суммы размернсоти массива
    static bool valid_array_size_for_sum(int size)
    {
        if (size > Constants::MAX_BUF)
        {
            ConsoleUI::error_message_dimension_biger_than_buff();
            return false;
        }
        if (size < 2)
        {
            ConsoleUI::error_message_dimension_lower_than_2();
            return false;
        }
        return true;
    }

    static bool valid_array_size_for_sort(int size)
    {
        if (size > Constants::MAX_BUF)
        {
            ConsoleUI::error_message_dimension_biger_than_buff();
            return false;
        }
        if (size < 1)
        {
            ConsoleUI::error_message_dimension_lower_than_1();
            return false;
        }
        return true;
    }

    // проверка на валидоность массива для суммы
    static bool valid_for_negative_sum(double *arr, int n)
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
    static bool valid_for_sort(double *arr)
    {
        if (arr == nullptr)
            return false;
        return true;
    }

    // проверка что массив не нулевой указатель перед анчалом выполнения работы для класса Data
    static bool valid_array_no_null(double *arr)
    {
        if (arr == nullptr)
        {
            return false;
        }
        return true;
    }

    // проверка что результат работы не нулевой указаетль для класса Aplication
    static bool valid_result_for_output_process_1(double *result_of_process_1)
    {
        return valid_array_no_null(result_of_process_1);
    }

    // функция для избежания бесконечной рекурсии
    static bool should_stop_sort(int low, int higt)
    {
        return low >= higt; // проверка правильности границ массива.

        /*Очевидно, что если массив начинается с индекса 5 и кончается индексом 0, то что то не так*/
    }
};