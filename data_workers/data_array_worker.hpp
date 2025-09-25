#include "../main_folder/common_constants.hpp" // импорт для namespace contains
#include "../processors/array_processor.hpp"  // импорт для проверки данных на валидность
#include "../helpers/sort_algorithm.hpp"   // для доступа к алгоритмам сортировки
#include "../core_types/validation_type.hpp"  // для ValidationType
#include "../main_folder/console_ui.hpp"       // импорт для работы с консольным интерфейсом
#include "../structures/result_array_worker_struct.hpp"
#pragma once // предотвращает многократное включение этого файла при импорте

/*Здесь хранятся только методы работы с данными класса и данные класса*/
template <typename T>
class Data_array_worker // класс для работы и харнения данных
{
private:                // доступно только внутри класса
    int n;              // размерность массива
    T *arr;             // массив
    int negative_count; // колчиество отрицтальных элементов
    int ind_min;
    int ind_max;
    Arr_and_size<int> min_ind_data;
    Arr_and_size<int> max_ind_data;

public: // доступно вне класса
    // конструктор по умолчанию
    Data_array_worker() : n(0), arr(nullptr), negative_count(0), ind_max(-1), ind_min(-1), min_ind_data(), max_ind_data() {} // через ":" мы инициализируем переменные сразу какие они нам нужны, тело {} пустое, так как мы уже присвоили им санчала нужные данные и действий не требуется
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
            throw std::invalid_argument("Error array");
        }
    }

    // ввод и проверка на валидность размерности массива для суммы
    void get_validated_array_dimension_for_sum()
    {
        int size = ConsoleUI::get_array_size();                              // запрос раземерности у интерфейса
        if (ArrayProcessor::valid_array_size(size, ValidationType::FOR_SUM)) // проверка размернсоти на валидность
        {
            this->n = size; // если валидный -присваиваем
            return;         // выходим из цикла и функции
        }
        throw std::invalid_argument("invalid dimension");
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

    void get_validated_array_dimension_for_product()
    {
        int size = ConsoleUI::get_array_size();                                  // запрос раземерности у интерфейса
        if (ArrayProcessor::valid_array_size(size, ValidationType::FOR_PRODUCT)) // проверка размернсоти на валидность
        {
            this->n = size; // если валидный -присваиваем
            return;         // выходим из цикла и функции
        }
        throw std::invalid_argument("invalid demenison");
    }

    // ввод и проверка массива для суммы
    void get_validated_array_for_sum()
    {
        T *arr = ConsoleUI::get_array_elements<T>(n);       // запрос у интерфейса элементов массива
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
        T *arr = ConsoleUI::get_array_elements<T>(n); // запрос у интерфейса элементов массива
        if (ArrayProcessor::valid_for_sort(arr))      // проверка массива на валидность
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
    void get_validated_array_for_product()
    {
        T *arr = ConsoleUI::get_array_elements<T>(n); // запрос у интерфейса элементов массива
        if (ArrayProcessor::valid_for_sort(arr))      // проверка массива на валидность
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

    // функция для присвоения классу уже готового массива
    void get_validated_array_for_sort(T *array)
    {
        if (ArrayProcessor::valid_for_sort(array)) // проверка массива на валидность
        {
            delete[] this->arr; // особождаем старый массив (хоть и не использовали, но он ячейка!)
            this->arr = array;  // присваиваем
            return;             // выходим из функции
        }
        else
        {
            this->arr = nullptr; // присваиваем Nullptr если не валидный
            return;              // выходим из функции
        }
    }

    // проверка на валидность размерности массива для суммы
    void get_validated_array_dimension_for_sort(int size)
    {
        if (ArrayProcessor::valid_array_size(size, ValidationType::FOR_SORT)) // проверка размернсоти на валидность
        {
            this->n = size; // если валидный -присваиваем
            return;         // выходим из цикла и функции
        }
        throw std::invalid_argument("invalid dimension");
    }

    // функция класса для сортировки массива
    T *sort_array()
    {
        return SortAlgorithm::quick_sort(this->arr, this->n);
    }

    // колчиество вхождений в массив
    static int count_of_occurrences_in_array(T *array, int size, T elem)
    {
        int counter = 0;
        for (int i = 0; i < size; i++)
        {
            if (array[i] == elem)
            {
                counter++;
            }
        }
        return counter;
    }

    // поиск максимального элемента массива, входящего в него боле раза
    T find_max_elem_occurrences_in_array_more_than_1_time(T *array, int size)
    {
        try
        {
            get_validated_array_dimension_for_sort(size);
        }
        catch (const std::invalid_argument &e)
        {
            throw(std::invalid_argument("incorrect dimension"));
        }
        get_validated_array_for_sort(array);
        T *array_sorted = sort_array();
        for (int i = 0; i < this->n; i++)
        {
            if (count_of_occurrences_in_array(array_sorted, this->n, array_sorted[this->n - i]) > 1)
            {
                T result = array_sorted[this->n - i];
                delete[] array_sorted;
                return result;
            }
        }
        delete[] array_sorted;
        throw(std::invalid_argument("the array is unique"));
    }

    T find_product_between_elements_index(int ind_min, int ind_max)
    {
        T product = 1;
        if (ind_min < ind_max)
        {
            for (int i = ind_min; i < ind_max; i++)
            {
                product = product * this->arr[i];
            }
            return product;
        }
        if (ind_min > ind_max)
        {
            for (int i = ind_max; i < ind_min; i++)
            {
                product = product * this->arr[i];
            }
            return product;
        }
        else
        {
            throw std::invalid_argument("min is max");
        }
    }

    int find_min_ind()
    {
        T abs_min = 1000000000000000000;
        int ind = 0;
        for (int i = 0; i < this->n; i++)
        {
            if (this->arr[i] < abs_min)
            {
                abs_min = this->arr[i];
                ind = i;
            }
        }
        return ind;
    }

    int find_max_ind()
    {
        T abs_max = -1000000000000000000;
        int ind = 0;
        for (int i = 0; i < this->n; i++)
        {
            if (this->arr[i] > abs_max)
            {
                abs_max = this->arr[i];
                ind = i;
            }
        }
        return ind;
    }

    int count_min()
    {
        T *arr_sorted = Data_array_worker::sort_array();
        int counter = 1;
        int i = 0;
        while (i < this->n - 1 && arr_sorted[i] == arr_sorted[i + 1])
        {
            i++;
            counter++;
        }
        delete[] arr_sorted;
        return counter;
    }

    int count_max()
    {
        T *arr_sorted = Data_array_worker::sort_array();
        int counter = 1;
        int i = 0;
        while (i < this->n - 1 && arr_sorted[this->n - 1 - i] == arr_sorted[this->n - 2 - i])
        {
            i++;
            counter++;
        }
        delete[] arr_sorted;
        return counter;
    }

    Arr_and_size<int> max_index_arr()
    {
        int *res = new int[Data_array_worker::count_max()];
        T *arr_sorted = Data_array_worker::sort_array();
        T max_value = arr_sorted[this->n - 1];
        int count = count_max();
        int res_index = 0;
        for (int i = 0; i < this->n; i++)
        {
            if (this->arr[i] == max_value)
            {
                res[res_index++] = i;
            }
        }
        delete[] arr_sorted;
        this->max_ind_data = Arr_and_size<int>(res, res_index);
        return Arr_and_size<int>(res, res_index);
    }

    Arr_and_size<int> min_index_arr()
    {
        int *res = new int[Data_array_worker::count_max()];
        T *arr_sorted = Data_array_worker::sort_array();
        T min_value = arr_sorted[0];
        int count = count_max();
        int res_index = 0;
        for (int i = 0; i < this->n; i++)
        {
            if (this->arr[i] == min_value)
            {
                res[res_index++] = i;
            }
        }
        delete[] arr_sorted;
        this->min_ind_data = Arr_and_size<int>(res, res_index);
        return Arr_and_size<int>(res, res_index);
    }

    void get_max_ind()
    {
        int tmp = ConsoleUI::get_index();
        if (ArrayProcessor::valid_ind_in_indices(tmp, this->n, this->max_ind_data.arr, this->max_ind_data.size))
        {
            this->ind_max = tmp;
            return;
        }
        throw(std::invalid_argument("invalid index"));
    }

    void get_min_ind()
    {
        int tmp = ConsoleUI::get_index();
        if (ArrayProcessor::valid_ind_in_indices(tmp, this->n, this->min_ind_data.arr, this->min_ind_data.size))
        {
            this->ind_min = tmp;
            return;
        }
        throw(std::invalid_argument("invalid index"));
    }

    T calculate_result_for_actions_if_min_or_max_count_more_1()
    {
        if (ArrayProcessor::valid_index_for_product_min_max(this->ind_max, this->ind_min))
        {
            return find_product_between_elements_index(this->ind_min, this->ind_max);
        }
        throw(std::invalid_argument("min and max in same index or radius lower than 3"));
    }

    T calculate_result_for_actions_for_process_2()
    {
        T *sorted_array = Data_array_worker::sort_array();
        if (ArrayProcessor::valid_min_and_max_unique_for_sort_array(sorted_array, this->n))
        {
            delete[] sorted_array;
            return find_product_between_elements_index(Data_array_worker::find_min_ind(), Data_array_worker::find_max_ind());
        }
        delete[] sorted_array;
        throw(std::invalid_argument("Not valid"));
    }
};