#include <iostream>
#include "common_constants.hpp" // импор для namespace contains
#include "array_processor.hpp"
#pragma once

using namespace std;

class Data
{
private:
    int n;                  // размерность массива
    double *arr;            // массив
    int negative_count = 0; // колчиество отрицтальных элементов

public:
    // функция нахождения суммы, индексов и колчества отрицательных элементов
    double *actions_for_process_1()
    {
        double sum = 0;
        int count_negative = 0;
        for (int i = 0; i < this->n; i++)
        {
            if (this->arr[i] < 0)
            {
                count_negative++;
                sum += arr[i];
            }
        }
        double *res = new double[count_negative + 2];
        int counter = 0; // счётчик количества элементов массива res
        for (int i = 0; i < this->n; i++)
        {
            if (this->arr[i] < 0)
            {
                res[counter] = i;
                counter++;
            }
        }
        res[counter] = sum;                // предпоследний элемент - сумма
        res[counter + 1] = count_negative; // последний - колчиество
        this->negative_count = count_negative;
        return res;
    }

    // посчет результата процесса 1
    double *calculate_result_for_process_1()
    {
        if (ArrayProcessor::valid_array_no_null(this->arr))
        {
            double *result_process_1 = this->actions_for_process_1();
            return result_process_1;
        }
        else{
            return nullptr;
        }
    }

    // ввод и проверка на валидность размерности массива
    void get_validated_array_dimension()
    {
        while (true)
        {
            int size = ConsoleUI::get_array_size();
            if (ArrayProcessor::valid_array_size(size))
            {
                this->n = size;
                return;
            }
        }
    }

    // ввод и проверка массива
    void get_validated_array()
    {
        double *arr = ConsoleUI::get_array_elements(n);
        if (ArrayProcessor::valid_for_negative_sum(arr, n))
        {
            this->arr = arr;
        }
        else
        {
            delete[] arr;
            this->arr = nullptr;
        }
    }

    int get_size()
    {
        return this->n;
    }

    int get_negative_count()
    {
        return this->negative_count;
    }
};