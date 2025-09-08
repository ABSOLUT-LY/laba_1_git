#include "common_constants.hpp" // для доступа к константам
#pragma once

/*Статические методы - можно использовать без экзмепляра класса и не имеют доступа к this*/

/*Здесь хранятся только логика для проверки данных дыумерных массивов*/
class MatrixProcessor
{
public:
    template <typename T>
    static int count_in_matrix(T **matrix, T elem, int row_count, int column_count)
    {
        int counter = 0;
        for (int i = 0; i < row_count; i++)
        {
            for (int g = 0; g < column_count; g++)
            {
                if (matrix[i][g] == elem)
                {
                    counter++;
                }
            }
        }
        return counter;
    }

    static bool valud_column_count(int column_count)
    {
        if (column_count > Constants::MAX_BUF)
        {
            return false;
        }
        if (column_count < 1)
        {
            return false;
        }
        return true;
    }

    static bool valid_row_count(int row_count)
    {
        if (row_count > Constants::MAX_BUF)
        {
            return false;
        }
        if (row_count < 1)
        {
            return false;
        }
        return true;
    }

    template <typename T>
    static bool row_contain_zeros(T *row, int column_count)
    {
        for (int i = 0; i < column_count; i++)
        {
            if (row[i] == 0)
            {
                return true;
            }
        }
        return false;
    }

    template <typename T>
    static bool valid_matrix_for_find_max(T **matrix, int row_count, int column_count)
    {
        for (int i = 0; i < row_count; i++)
        {
            for (int g = 0; g < column_count; g++)
            {
                if (count_in_matrix(matrix, matrix[i][g], row_count, column_count) > 1)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
