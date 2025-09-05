#include <iostream>
#include "common_constants.hpp" // импор для namespace contains
#pragma once

using namespace std;

class ConsoleUI
{
public:
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

    // отрисовка экарана задания 1
    static void message_exercise_1_screen()
    {
        cout << "1" << "\t" << "Calculate the sum of negative elements of the array, determine their number and find their coordinates;" << endl;
        cout << "2" << "\t" << "Calculate the product of array elements located between the maximum and minimum element, indicating their position in the array;" << endl;
        cout << "3" << "\t" << "Sort array elements in ascending order" << endl;
        cout << "Select and enter the number of the operation you need:" << "\t";
    }

    // диалог для возврата на главный экран
    static void homescreen_message()
    {
        char letter;
        while (true)
        {
            cout << endl
                << "Do you want return on main screen [Y/N]?" << endl;
            cin >> letter;
            switch (letter)
            {
            case 'Y':
                clear_terminal();
                return;

            case 'N':
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

    // сообщение о корректном вводе размернсти
    static void message_correct_dimension()
    {
        cout << "Correct" << endl;
    }

    // сообщение о создании массива
    static void message_correct_create_array()
    {
        cout << "Array created" << endl;
    }

    // сообщение о ошибке наличия негативных элементов
    static void error_message_negative_count(int nc)
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
    static void error_message_no_negative_elements()
    {
        cout << "Operation failed: no negative elements found." << endl;
    }

    // сообщеине о ошибке резмерность более буфера
    static void error_message_dimension_biger_than_buff()
    {
        cout << "Dimension greater than maximum buff" << endl;
    }

    // сообщение о ошибке размерность мнее 2
    static void error_message_dimension_lower_than_2()
    {
        cout << "Dimension lower than 2" << endl;
    }

    // ввод размернсоти
    static int get_array_size()
    {
        int size;
        cout << "Enter the array dimension (no more than " << Constants::MAX_BUF << "):" << endl;
        cin >> size;
        return size;
    }

    // Ввод элементов массива
    static double* get_array_elements(int n)
    {
        double *arr = new double[n];
        cout << "Enter the array elements (separated by enter):" << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        message_correct_create_array;
        return arr;
    }

    // ФУНКЦИИ ДЛЯ ВЫВОДА РЕЗУЛЬТАТОВ РАБОТЫ ПРОЦЕССОВ
    static void output_res_process_1(double* result_process_1, int negative_count)
    {
        // Вывод количества отрицательных элементов
        cout << "Number of negative elements \t" << result_process_1[negative_count] << endl;

        // Вывод суммы отрицательных элементов
        cout << "Sum of negative elements \t" << result_process_1[negative_count + 1] << endl;

        // Вывод элементов массива
        cout << "Index of negative array elements: ";
        for (int i = 0; i < negative_count; i++)
        {
            cout << result_process_1[i] << " ";
        }
        cout << endl;
        delete[] result_process_1;
    }
};
