#include <iostream>
#include <cstdlib>
#include "laba_1.1.1.h"

using namespace std;

// ФУНКЦИИ ДЛЯ UI

// oчистка терминала
void clear_terminal()
{
    system("cls");
}

// диалог для возврата на главный экран
void homescreen_message()
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

// функция для действия 1 задания 1 в терминале
void process_1_terminal()
{
    clear_terminal();
    Exercise_1 ex_1;
    clear_terminal();
    ex_1.input_dimension();
    clear_terminal();
    ex_1.input_arr();
    clear_terminal();
    ex_1.output_actions_for_process_1();
    homescreen_message();
}

// функция для действия 2 задания 1 в терминале
void process_2_terminal()
{
}

// функция для действия 3 задания 1 в терминале
void process_3_terminal()
{
}

// задание 1
void screen_exercise_1_terminal()
{
    clear_terminal();
    int k = 0; // Номер оперцаии
    cout << "1" << "\t" << "Calculate the sum of negative elements of the array, determine their number and find their coordinates;" << endl;
    cout << "2" << "\t" << "Calculate the product of array elements located between the maximum and minimum element, indicating their position in the array;" << endl;
    cout << "3" << "\t" << "Sort array elements in ascending order" << endl;
    cout << "Select and enter the number of the operation you need:" << "\t";
    while (true)
    {
        cin >> k;
        switch (k)
        {
        case 1:
            process_1_terminal();
            return;
        case 2:
            return;
        case 3:
            return;
        default:
            cout << "Invalid operation number. Try again:" << "\t";
            break;
        }
    }
}

// функция для создания и работы с программой
void terminal_process()
{
    int k = 0; // Номер задания
    cout << "Welcome to the program!" << endl;
    cout << "1. Exercise 1;" << endl;
    cout << "2. Exercise 2;" << endl;
    cout << "3. Exercise 3;" << endl;
    cout << "Select and enter the task number:" << "\t";
    while (true)
    {
        cin >> k;
        switch (k)
        {
        case 1:
            screen_exercise_1_terminal();
            terminal_process();
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            cout << "Invalid operation number. Try again:" << "\t";
            break;
        }
    }
}

int main()
{
    terminal_process();
}