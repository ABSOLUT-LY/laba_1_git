#include <iostream>
#include "common_constants.hpp" // импор для namespace contains
#include "console_ui.hpp"
#pragma once

using namespace std;

class ArrayProcessor{
    public:
    // проверка на валидность размернсоти массива
    static bool valid_array_size(int size){
        if (size > Constants::MAX_BUF){
            ConsoleUI::error_message_dimension_biger_than_buff();
            return false;
        }
        if (size < 2){
            ConsoleUI::error_message_dimension_lower_than_2();
            return false;
        }
        return true;
    }
    // проверка на валидоность массива
    static bool valid_for_negative_sum(double* arr, int n)
    {
        int negative_count = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < 0)
            {
                negative_count++;
            }
        }
        if (not(negative_count))
        {
            ConsoleUI::error_message_negative_count(negative_count);
            return false;
        }
        if (negative_count < 2)
        {
            ConsoleUI::error_message_negative_count_lower_than_two();
            return false;
        }
        return true;
    }

    static bool valid_array_no_null(double* arr){
        if (arr == nullptr){
            return false;
        }
        return true;
    }

    static bool valid_result_for_output_process_1(double* result_of_process_1){
        return valid_array_no_null(result_of_process_1);
    }
};