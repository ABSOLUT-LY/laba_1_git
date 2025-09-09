#include "matrix_processor.hpp"            // для доступа к логике
#include "console_ui.hpp"                 // импорт для работы с консольным интерфейсом
#include "result_matrix_worker_struct.hpp" // для структуры резульата
#include "data_array_worker.hpp"                         //для методов массива

#pragma once
template <typename T>
class Data_matrix_worker
{
private:
    int row_count;                // Колчиество строк
    int column_count;             // колчисетво стлобцов
    T **matrix;                   // сама матрица
    int count_zeros_contain_rows; // колчиество строк, содержащих 0

    // поиск колества строк не содрежащих нулевых жлементов
    int find_count_row_not_contain_zeros()
    {
        int counter = 0;
        for (int i = 0; i < this->row_count; i++)
        {
            if (MatrixProcessor::row_contain_zeros(this->matrix[i], this->column_count))
            {
                continue;
            }
            else
            {
                counter++;
            }
        }
        return counter;
    }

    // поиск индексов строк матрицы не содеращих нулевых элементов
    int *find_index_row_not_contain_zeros()
    {
        int *result = new int[this->count_zeros_contain_rows]; // массив для индексов строк матриц содержащих 0
        int ind_k = 0;                                         // счётчик добавленных в массив индексов
        for (int i = 0; i < this->row_count; i++)
        {
            if (MatrixProcessor::row_contain_zeros(this->matrix[i], this->column_count))
            {
                continue;
            }
            else
            {
                result[ind_k] = i;
                ind_k++;
            }
        }
        return result;
    }

    // матрциа -> массив
    T *matrix_to_arr()
    {
        T *arr = new T[row_count * column_count];
        for (int i = 0; i < this->row_count; i++)
        {
            for (int g = 0; g < this->column_count; g++)
            {
                arr[i * this->column_count + g] = this->matrix[i][g];
            }
        }
        return arr;
    }

public:
    Data_matrix_worker() : row_count(0), column_count(0), matrix(nullptr), count_zeros_contain_rows(0) {}; // стандартный конструктор
    ~Data_matrix_worker()
    {
        if (matrix != nullptr)
        {
            for (int i = 0; i < row_count; ++i)
            {
                delete[] matrix[i]; // Освобождаем каждую строку
            }
            delete[] matrix; // Освобождаем массив указателей
        }
    }; // деструктор

    // получение колчесва строк матрицы из консоли
    void get_matrix_row_count()
    {
        int row_count_tmp = ConsoleUI::get_row_count();
        if (MatrixProcessor::valid_row_count(row_count_tmp))
        {
            this->row_count = row_count_tmp;
            return;
        }
        throw(std::invalid_argument("invalid row count"));
    }

    int get_count_zeros_contain_rows()
    {
        return this->count_zeros_contain_rows;
    }

    // получение колчесва столбцов матрицы из консоли
    void get_matrix_column_count()
    {
        int column_count_tmp = ConsoleUI::get_column_count();
        if (MatrixProcessor::valud_column_count(column_count_tmp))
        {
            this->column_count = column_count_tmp;
            return;
        }
        throw(std::invalid_argument("invalid column count"));
    }

    // получение элементов матрицы
    void get_matrix_elements()
    {
        T **matrix_tmp = ConsoleUI::get_matrix_elements<T>(this->row_count, this->column_count);
        this->matrix = matrix_tmp;
    }

    // поиск колчества строк не содержащих ни одного нулевого элемента и их координаты
    ZeroFreeRowIndexes calculate_result_action_1()
    {
        this->count_zeros_contain_rows = Data_matrix_worker::find_count_row_not_contain_zeros();
        return ZeroFreeRowIndexes(Data_matrix_worker::find_index_row_not_contain_zeros(), this->count_zeros_contain_rows);
    }

    static int *find_in_matrix(T **matrix, T elem, int row_count, int column_count)
    {
        int *result = new int[2];
        result[0] = -1;
        result[1] = -1;
        for (int y = 0; y < row_count; y++)
        {
            for (int x = 0; x < column_count; x++)
            {
                if (matrix[y][x] == elem)
                {
                    return result;
                }
            }
        }
        return result;
    }

    MaxElemAndIndex<T> calculate_result_action_2()
    {
        if (MatrixProcessor::valid_matrix_for_find_max(this->matrix, this->row_count, this->column_count))
        {
            MaxElemAndIndex<T> result;
            Data_array_worker<T> arr_worker;
            T elem = arr_worker.find_max_elem_occurrences_in_array_more_than_1_time(matrix_to_arr(), this->row_count * this->column_count);
            int *coordinates = find_in_matrix(this->matrix, elem, this->row_count, this->column_count);
            result.max_elem = elem;
            result.index_x = coordinates[0];
            result.index_y = coordinates[1];
            return result;
        }
        else
        {
            throw std::invalid_argument("Error matrix");
        }
    }
};