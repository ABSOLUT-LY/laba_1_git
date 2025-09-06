#include "common_constants.hpp" // импорт для namespace contains
#include "array_processor.hpp"  // импорт для проверки данных на валидность
#include "sort_algorithm.hpp"   // для доступа к алгоритмам сортировки
#include "validation_type.hpp"  // для ValidationType
#include "console_ui.hpp"       // импорт для работы с консольным интерфейсом
#pragma once                    // предотвращает многократное включение этого файла при импорте

/*Здесь хранятся только методы работы с данными класса и данные класса*/

class Data_array_worker // класс для работы и харнения данных
{
private:                // доступно только внутри класса
    int n;              // размерность массива
    double *arr;        // массив
    int negative_count; // колчиество отрицтальных элементов

public: // доступно вне класса
    // конструктор по умолчанию
    Data_array_worker() : n(0), arr(nullptr), negative_count(0) {} // через ":" мы инициализируем переменные сразу какие они нам нужны, тело {} пустое, так как мы уже присвоили им санчала нужные данные и действий не требуется
    // деструктор
    ~Data_array_worker()
    {
        delete[] arr; // освобождаем память массива
    }

    // функция нахождения суммы, индексов и колчества отрицательных элементов
    double *actions_for_process_1()
    {
        double sum = 0;                   // сумма отрицательных элементов
        int count_negative = 0;           // колчество отрицательных элементов
        for (int i = 0; i < this->n; i++) // цикл для прохода по всему массиву
        {
            if (this->arr[i] < 0) // если отрицательных
            {
                count_negative++; // +колчиество отрицтальеных
                sum += arr[i];    // + к сумме отрицательных
            }
        }
        double *res = new double[count_negative + 2]; // выходной маасив из индексов отрицталеьных элементов на 2 элементаа более так как написано снизу
        int counter = 0;                              // счётчик количества элементов массива res
        for (int i = 0; i < this->n; i++)             // снова проходимя по массиву
        {
            if (this->arr[i] < 0) // если отрицательный
            {
                res[counter] = i; // записываем индекс отрицательного элемента
                counter++;        // увеличиваем количество отрицательных элементов
            }
        }
        res[counter] = sum;                    // предпоследний элемент - сумма
        res[counter + 1] = count_negative;     // последний - колчиество
        this->negative_count = count_negative; // запеисываем колчиество отрицательных элементов - понадобится для вывода
        return res;                            // возвращаем массив
    }

    // подсчет результата процесса 1
    double *calculate_result_for_process_1()
    {
        if (ArrayProcessor::valid_array_no_null(this->arr)) // если массив является валидным
        {
            double *result_process_1 = this->actions_for_process_1(); // выполняем действия процесса 1
            return result_process_1;                                  // возвращаем резульатат действия выше
        }
        else
        {
            return nullptr; // если не корректен - nullptr
        }
    }

    // ввод и проверка на валидность размерности массива для суммы
    void get_validated_array_dimension_for_sum()
    {
        while (true) // пока ввод размерности не будет правильным
        {
            int size = ConsoleUI::get_array_size();                              // запрос раземерности у интерфейса
            if (ArrayProcessor::valid_array_size(size, ValidationType::FOR_SUM)) // проверка размернсоти на валидность
            {
                this->n = size; // если валидный -присваиваем
                return;         // выходим из цикла и функции
            }
        }
    }

    // ввод и проверка на валидность размерности массива для сортировки
    void get_validated_array_dimension_for_sort()
    {
        while (true) // пока ввод размерности не будет правильным
        {
            int size = ConsoleUI::get_array_size();                               // запрос раземерности у интерфейса
            if (ArrayProcessor::valid_array_size(size, ValidationType::FOR_SORT)) // проверка размернсоти на валидность
            {
                this->n = size; // если валидный -присваиваем
                return;         // выходим из цикла и функции
            }
        }
    }

    // ввод и проверка массива для суммы
    void get_validated_array_for_sum()
    {
        double *arr = ConsoleUI::get_array_elements(n);     // запрос у интерфейса элементов массива
        if (ArrayProcessor::valid_for_negative_sum(arr, n)) // проверка массива на валидность
        {
            delete[] this->arr; // особождаем старый массив (хоть и не использовали, но он ячейка!)
            this->arr = arr;    // присваиваем
            return;             // выходим из функции
        }
        else
        {
            delete[] arr;        // очизаем память если не валидный
            this->arr = nullptr; // присваиваем Nullptr если не валидный
            return;              // выходим из функции
        }
    }

    // ввод и проверка массива для сортировки
    void get_validated_array_for_sort()
    {
        double *arr = ConsoleUI::get_array_elements(n); // запрос у интерфейса элементов массива
        if (ArrayProcessor::valid_for_sort(arr))        // проверка массива на валидность
        {
            delete[] this->arr; // особождаем старый массив (хоть и не использовали, но он ячейка!)
            this->arr = arr;    // присваиваем
            return;             // выходим из функции
        }
        else
        {
            delete[] arr;        // очизаем память если не валидный
            this->arr = nullptr; // присваиваем Nullptr если не валидный
            return;              // выходим из функции
        }
    }

    // получение размернсоти массива без возможности изменять
    int get_size() const
    {
        return this->n; // возвращает размерность массива
    }

    // получение количества отрицательных элементов без возможности их изенения
    int get_negative_count() const
    {
        return this->negative_count; // возвращаем количество отрицатльных элементов
    }

    // функция для сортировки массива
    double *sort_array()
    {
        return SortAlgorithm::quick_sort(this->arr, this->n);
    }
};