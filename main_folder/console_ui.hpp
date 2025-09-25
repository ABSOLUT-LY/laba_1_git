#include <iostream>                        // ввыод/вывод
#include "common_constants.hpp"            // импор для namespace contains
#include "../core_types/error_type.hpp"                  // для ValidationType
#include <istream>                         // для getline
#include "../core_types/screen_console_options.hpp"      //для вариатнов выбора в консоли
#include "../structures/result_matrix_worker_struct.hpp" //струкутра для результатов matrix_worker
#include "../structures/result_array_worker_struct.hpp"

#pragma once // предотвращает многократное включение этого файла при импорте

using namespace std; // для cin и cout

/*Статические методы - можно использовать без экзмепляра класса и не имеют доступа к this*/

/*Здесь хранятся только сообщения для ввода и вывода никакой логики*/

class ConsoleUI // класс для работы с консольным интерфейсом
{
private:
    // приват

    // сообщение о корректном вводе размернсти
    static void message_correct_dimension()
    {
        cout << "Correct" << endl;
    }

    // сообщение о вводе предложений в файл
    static void message_about_senteces_in_file()
    {
        cout << "A maximum of 1024 characters will be read (including signs and spaces)" << endl
             << "Do not split sentences with Enter!" << endl
             << "Only text in English!" << endl
             << "Check your file before you start working" << endl;
    }

    // сообщение о вводе имени файла
    static void message_input_name_file()
    {
        cout << "Enter the file name, without spaces, in English only, specifying its type." << endl
             << "A maximum of 1024 characters will be read" << endl
             << "the file must be in the park es project!" << endl
             << "Example:<example.txt>" << endl;
    }

    // сообщение о вооде размерности массива
    static void message_input_dimension_array()
    {
        cout << "Enter the array dimension (no more than " << Constants::MAX_BUF << "):" << endl;
    }

    // сообщение о вводе жлементов масиива
    static void message_input_array_elements()
    {
        cout << "Enter the array elements (separated by enter):" << endl;
    }

    // сообщение о вводе количества строк
    static void message_input_matrix_row_count()
    {
        cout << "Enter the number of matrix rows: " << endl;
    }

    // сообщение о вводе количества столбцов
    static void message_input_matrix_column_count()
    {
        cout << "Enter the number of columns in the matrix: " << endl;
    }

    // сообщение о вводе колчетсва столбцов
    static void message_input_matrix()
    {
        cout << "Enter matrix elements: " << endl;
    }

    static void message_input_max_index()
    {
        cout << "Enter the index of the desired maximum element: " << endl;
    }

    static void message_input_min_index()
    {
        cout << "Enter the index of the desired minimum element: " << endl;
    }

    // сообщение  ошибке колччества строк
    static void error_message_row_count()
    {
        cout << "Error, the number of rows must not be less than 1" << endl;
    }

    // сообщение о ошибке оклчества строк
    static void error_message_column_count()
    {
        cout << "Error, the number of columns must not be less than 1" << endl;
    }

    // сообщение о ошибке содержания матрицы для поиска элемента встречащегося более 1 раза
    static void error_matrix_is_unique()
    {
        cout << "The array is unique, it is impossible to complete the task" << endl;
    }

    static void error_matrix_has_no_rows_contained_zeros()
    {
        cout << "There are all matrix rows containing zeros." << endl;
    }

    // сообщение о ошибке наличия негативных элементов
    static void
    error_message_negative_count(int nc)
    {
        cout << "Error, no negative elements" << endl;
    }

    // сообщение о ошибке наличия негативных элементов
    static void error_message_negative_count_lower_than_two()
    {
        cout << "Error, count of negative elements lower then two" << endl;
    }

    // сообщение о ошибке расстояния между максимальным и минимальным элементами
    static void error_message_max_min_no_distance(int distance)
    {
        cout << "Error, distance between max and min elements " << distance << " expected 2 or more" << endl;
    }

    // сообщение о ошибке отсутсвия отрицатльных элементов
    static void error_message_count_negative_elements_lower_than_2()
    {
        cout << "Operation failed: the number of negative elements is less than 2" << endl;
    }

    // сообщеине о ошибке резмерность более буфера
    static void error_message_dimension_biger_than_buff()
    {
        cout << "Dimension greater than maximum buff: " << Constants::MAX_BUF << endl;
    }

    // сообщение о ошибке размерность мене 2
    static void error_message_dimension_lower_than_2()
    {
        cout << "Dimension lower than 2 or greater than maximum buff: " << Constants::MAX_BUF << endl;
    }

    // сообщение о ошибке размерность мене 1
    static void error_message_dimension_lower_than_1()
    {
        cout << "Dimension lower than 1 or greater than maximum buff: " << Constants::MAX_BUF << endl;
    }

    static void error_message_dimension_lower_than_4()
    {
        cout << "Dimension lower than 4 or greater than maximum buff: " << Constants::MAX_BUF << endl;
    }

    // вывод сообщения о ошибке символов
    static void error_message_symbols()
    {
        cout << "Error: sentences do not contain letters or are not in English" << endl;
    }

    // вывод сообщения о ошибке колчиества строк
    static void error_message_senteces_count()
    {
        cout << "Error: expected " << Constants::MAX_COUNT_SENTENCES << " strings" << endl;
    }

    // вывод сообщения о ошибке колчиества строк
    static void error_message_string_in_file_is_empty()
    {
        cout << "Error: file is empty" << endl;
    }

    // вывод сообщения о ошибке строки
    static void error_message_string(Error_string type_error)
    {
        switch (type_error)
        {
        case Error_string::SYMBOLS_ERROR:
            error_message_symbols();
            return;
        case Error_string::COUNT_SENTENCES_ERROR:
            error_message_senteces_count();
            return;
        }
    }

    // вывод сообщения о отсутсвии файла
    static void error_file_does_not_exists()
    {
        cout << "File does not exists" << endl;
    }

    // ВЫвод сообщения о ошибке имнеи файла
    static void error_name_file()
    {
        cout << "Invalid file name. Try again. (press Enter before starting a new entry)" << endl;
    }

    // выовд сообщения о неизвестной ошибке
    static void unknown_error()
    {
        cout << "An unknown error occurred." << endl;
    }

    // вывод сообщения о ошибке результата
    static void error_content_string()
    {
        cout << "There was a problem with the file contents." << endl;
    }

    // Вовод сообщения о неверном номере опреации
    static void error_message_invalid_operation_number()
    {
        cout << "Invalid operation number. Try again:" << "\t";
    }

    // отрисовка экарана задания 1
    static void message_exercise_1_screen()
    {
        cout << "1" << "\t" << "Calculate the sum of negative elements of the array, determine their number and find their coordinates;" << endl;
        cout << "2" << "\t" << "Calculate the product of array elements located between the maximum and minimum element, indicating their position in the array;" << endl;
        cout << "3" << "\t" << "Sort array elements in ascending order" << endl;
        cout << "Select and enter the number of the operation you need:" << "\t";
    }

    // отрисовка экарана задания 2
    static void message_exercise_2_screen()
    {
        cout << "1" << "\t" << "The number of rows that do not contain any zero elements and their coordinates;" << endl;
        cout << "2" << "\t" << "The maximum number that appears in the given matrix more than once and its position in the array" << endl;
        cout << "Select and enter the number of the operation you need:" << "\t";
    }

    // отрисовка экарана задания 3
    static void message_exercise_3_screen()
    {
        cout << "" << endl;
    }

    // диалог для возврата на главный экран
    static void want_to_homescreen_message_dialog()
    {
        char letter;
        while (true)
        {
            cout << endl
                 << "Do you want return on main screen [Y/N]?" << endl;
            cin >> letter;
            clean_input_stream();
            switch (letter)
            {
            case 'Y':
                clear_terminal();
                return;
            case 'y':
                clear_terminal();
                return;
            case 'N':
                exit(0);
            case 'n':
                exit(0);
            default:
                cout << "Invalid choice. Try again." << endl;
            }
        }
    }

    // отрисовка начального экрана
    static void message_homescreen()
    {
        cout << "Welcome to the program!" << endl;
        cout << "1. Exercise 1;" << endl;
        cout << "2. Exercise 2;" << endl;
        cout << "3. Exercise 3;" << endl;
        cout << "Select and enter the task number:" << "\t";
    }

public:
    // очистка ввода
    static void clean_input_stream()
    {
        while (cin.get() != '\n')
        {
            continue;
        }
    }
    // Очистка терминала
    static void clear_terminal()
    {
        system("cls");
    }

    // ФУНКЦИИ ДЛЯ СООБЩЕНИЙ UI

    // Пример функции для сообщения о ошибке
    // void error_message_{причина ошибки}()
    // {
    //     cout << "Ошибка,..." << endl;
    // }

    // паблик

    // ввод размернсоти
    static int get_array_size()
    {
        int size;
        cin >> size;
        return size;
    }

    // ввод имени файла
    static char *get_file_name()
    {
        char *arr = new char[Constants::MAX_BUFF_STRING];
        // cin.clear();
        // cin.ignore(Constants::MAX_BUFF_STRING, '\n');
        cin.getline(arr, Constants::MAX_BUFF_STRING + 1);
        clean_input_stream();
        return arr;
    }

    // Ввод элементов массива
    template <typename T>
    static T *get_array_elements(int n)
    {
        T *arr = new T[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        return arr;
    }

    // ввод колчиество строк матрицы
    static int get_row_count()
    {
        int row_count;
        cin >> row_count;
        return row_count;
    }

    // ввод кличество строк матрицы
    static int get_column_count()
    {
        int column_count;
        cin >> column_count;
        return column_count;
    }

    static int get_index()
    {
        int index;
        cin >> index;
        return index;
    }

    // ввод элементов матрицы
    template <typename T>
    static T **get_matrix_elements(int row_count, int column_count)
    {
        T **matrix = new T *[row_count];
        T *tmp;
        for (int i = 0; i < row_count; i++)
        {
            tmp = new T[column_count];
            for (int g = 0; g < column_count; g++)
            {
                cin >> tmp[g];
            }
            matrix[i] = tmp;
        }
        return matrix;
    }

    // ФУНКЦИИ ДЛЯ ВЫВОДА РЕЗУЛЬТАТОВ РАБОТЫ ПРОЦЕССОВ

    // вывод рещультата задачи 1 процесса 1
    template <typename T>
    static void output_res_process_1_exercise_1(T *result_process_1, int negative_count)
    {
        // Вывод количества отрицательных элементов
        cout << "Number of negative elements \t" << result_process_1[negative_count + 1] << endl;

        // Вывод суммы отрицательных элементов
        cout << "Sum of negative elements \t" << result_process_1[negative_count] << endl;

        // Вывод элементов массива
        cout << "Index of negative array elements: ";
        for (int i = 0; i < negative_count; i++)
        {
            cout << result_process_1[i] << " ";
        }
        cout << endl;
    }

    template <typename T>
    static void min_index_choise_dialog(Arr_and_size<T> res)
    {
        cout << "Minimum indices: ";
        for (int i = 0; i < res.size; i++)
        {
            cout << res.arr[i] << " ";
        }
        cout << endl;
    }

    template <typename T>
    static void max_index_choise_dialog(Arr_and_size<T> res)
    {
        cout << "Maximum indices: ";
        for (int i = 0; i < res.size; i++)
        {
            cout << res.arr[i] << " ";
        }
        cout << endl;
    }

    template <typename T>
    // вывод рещультата задачи 2 процесса 3
    static void output_res_process_2_exercise_1(T res)
    {
        cout << "Product of elements: ";
        cout << res << endl;
    }

    // вывод рещультата задачи 3 процесса 3
    template <typename T>
    static void output_res_process_3_exercise_1(T *result_process_2, int n)
    {
        cout << "Sorted array using Quicksort method: ";
        for (int i = 0; i < n; i++)
        {
            cout << result_process_2[i] << " ";
        }
        cout << endl;
    }

    static void output_res_process_1_exercise_2(ZeroFreeRowIndexes result, int n)
    {
        cout << "Number of rows that do not contain any null elements: " << result.count << endl;
        cout << "Coordinates of rows that do not contain any zero elements: ";
        for (int i = 0; i < n; i++)
        {
            cout << result.indexes[i] << " ";
        }
        cout << endl;
    }

    template <typename T>
    static void output_res_process_2_exercise_2(MaxElemAndIndex<T> result)
    {
        cout << "The maximum element of a matrix that occurs more than once: " << result.max_elem << endl;
        cout << "Coordinates: X = " << result.index_x << " Y = " << result.index_y << endl;
    }

    // вывод рещультата задачи 3
    static void output_res_exercise_3(char *str)
    {
        cout << "Line in reverse order:" << endl
             << endl;
        int ind = 0;
        while (str[ind] != '\0')
        {
            cout << str[ind];
            ind++;
        }
        cout << endl;
        return;
    }

    // вывод экранов выбора
    static void handler_screen_programm(AppOptions value)
    {
        switch (value)
        {
        case AppOptions::EX_1:
            message_exercise_1_screen();
            break;
        case AppOptions::EX_2:
            message_exercise_2_screen();
            break;
        case AppOptions::EX_3:
            message_exercise_3_screen();
            break;
        case AppOptions::HOMESCREEN_DIALOG:
            want_to_homescreen_message_dialog();
            break;
        case AppOptions::HOMESCREEN:
            message_homescreen();
            break;
        }
    }

    // единый вывод сообщений для задания 1
    static void handler_screen_exercise_1(Exercise_1 value)
    {
        switch (value)
        {
        case Exercise_1::ARRAY_INPUT:
            message_input_array_elements();
            break;
        case Exercise_1::DIMENSION_INPUT:
            message_input_dimension_array();
            break;
        case Exercise_1::IND_MAX_INPUT:
            message_input_max_index();
            break;
        case Exercise_1::IND_MIN_INPUT:
            message_input_min_index();
            break;
        default:
            break;
        }
    }

    static void handler_screen_exercise_2(Exercise_2 value)
    {
        switch (value)
        {
        case Exercise_2::COUNT_COLUMN_INPUT:
            message_input_matrix_column_count();
            break;
        case Exercise_2::COUNT_ROWS_INPUT:
            message_input_matrix_row_count();
            break;
        case Exercise_2::MATRIX_INPUT:
            message_input_matrix();
            break;
        default:
            break;
        }
    }

    static void handler_screen_exercise_3(Exercise_3 value)
    {
        switch (value)
        {
        case Exercise_3::FILE_NAME:
            message_input_name_file();
            break;
        default:
            break;
        }
    }

    // единая функция для обработки ошибко по коду
    static void handler_error_main_app(App_error error_code)
    {
        switch (error_code)
        {
        case App_error::UNKNOWN_ERROR:
            unknown_error();
            break;
        case App_error::INVALID_OPERATION_NUMBER:
            error_message_invalid_operation_number();
            break;
        default:
            break;
        }
    }

    // сообщение о ошибке файла
    static void handler_error_file_message(Error_file type_error)
    {
        switch (type_error)
        {
        case Error_file::FILE_DOES_NOT_EXIST:
            error_file_does_not_exists();
            break;
        case Error_file::FILE_NAME_ERROR:
            error_name_file();
            break;
        default:
            break;
        }
    }

    // вывод сообщения о ошибке раземрности
    static void handler_error_message_dimension(Error_dimension_array type_error)
    {
        switch (type_error)
        {
        case Error_dimension_array::SUM_ERROR:
            error_message_dimension_lower_than_2(); // размерность меньше 2 или более буфера - нельзя найти сумму
            return;
        case Error_dimension_array::SORT_ERROR:
            error_message_dimension_lower_than_1(); // размерность меньше 1 или более буфера- нельзя сортировать
            return;
        case Error_dimension_array::PRODUCT_ERROR:
            error_message_dimension_lower_than_4();
            return;
        }
    }

    static void error_message_index()
    {
        cout << "Invalid index" << endl;
    }

    static void error_message_input_indices()
    {
        cout << "Error the distance between selected indices must be more than 3" << endl;
    }

    static void handler_error_message_dimension_matrix(Error_dimension_matrix type_error)
    {
        switch (type_error)
        {
        case Error_dimension_matrix::INVALID_ROW_COUNT:
            error_message_row_count();
            break;
        case Error_dimension_matrix::INVALID_COLUMN_COUNT:
            error_message_column_count();
            break;
        default:
            break;
        }
    }

    static void handler_error_message_matrix_content(Error_matrix type_error)
    {
        switch (type_error)
        {
        case Error_matrix::INVALID_MATRIX_FOR_FIND_SUM:
            error_matrix_is_unique();
            break;
        case Error_matrix::NO_ZEROS_ROWS:
            error_matrix_has_no_rows_contained_zeros();
            break;
        default:
            break;
        }
    }

    // единый метод вывода сообщений о ошибке содержания массива
    static void handler_error_message_array_elements(Error_array_content type_error)
    {
        switch (type_error)
        {
        case Error_array_content::ERROR_COUNT_NEGATIVE_ELEMENTS_FOR_SUM:
            error_message_count_negative_elements_lower_than_2();
            break;
        default:
            break;
        }
    }

    // единый метод вывода ошибок о содержании строки
    static void handler_error_messge_string_content(Error_string type_error)
    {
        switch (type_error)
        {
        case Error_string::CONTENT_STRING_ERROR:
            error_content_string();
            break;
        case Error_string::COUNT_SENTENCES_ERROR:
            error_message_senteces_count();
            break;
        case Error_string::SYMBOLS_ERROR:
            error_message_symbols();
            break;
        case Error_string::STRING_EMPTY:
            error_message_string_in_file_is_empty();
            break;
        default:
            break;
        }
    }
};
