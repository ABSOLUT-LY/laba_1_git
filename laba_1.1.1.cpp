#include <iostream>

#define MAX_BUFF 200

using namespace std;

// глобальная переменная размерности массива
int n;

// ФУНКЦИИ ДЛЯ ОШИБОК

// Пример функции для сообщения о ошибке
// void error_message_{причина ошибки}()
// {
//     cout << "Ошибка,..." << endl;
// }

// сообщение о ошибке наличия негативных элементов
void error_message_negative_count(int nc)
{
    cout << "Error, no negative elements" << endl;
}

// сообщение о ошибке расстояния между максимальным и минимальным элементами
void error_message_max_min_no_distance(int distance)
{
    cout << "Error, distance between max and min elements " << distance << " expected 2 or more" << endl;
}

// ФУНКЦИИ ДЛЯ ВВОДА

// функция ввода массива
template <typename T>
T *input_arr()
{
    T *arr = new T[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    return arr;
}

// ввод ращмерности массива и проверка его на соответсвие буферу
void input_dimension()
{
    cout << "Enter the array dimension (no more than " << MAX_BUFF << ")" << endl;
    cin >> n;
    while (true)
    {
        if (n > MAX_BUFF)
        {
            cout << "dimension greater than " << MAX_BUFF << " .Try again." << endl;
            cin >> n;
        }
        else
        {
            cout << endl
                 << "Array created";
            break;
        }
    }
}

// ФУНКЦИИ ДЛЯ РАБОТЫ С ДАННЫМИ

// функция проверки массива на валидность для суммы отрицательных чисел перед началом работы
template <typename T>
bool valid_for_negative_sum(T *arr)
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
        error_message_negative_count(negative_count);
        return false;
    }
    return true;
}

// функция нахождения суммы, индексов и колчества отрицательных элементов
template <typename T>
T *actions_for_process_1(T *arr)
{
    T sum = 0;
    int count_negative = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            res[count_negative] = i;
            count_negative++;
            sum += arr[i];
        }
    }
    T *res = new double[count_negative + 2];
    for (int i = 0; i < count_negative; i++)
    {
    }
    res[count_negative + 1] = sum;
    res[count_negative + 2] = count_negative;
    return res;
}

// ФУНКЦИИ ДЛЯ ВЫВОДА РЕЩУЛЬТАТОВ РАБОТЫ ПРОЦЕССОВ
template <typename T>
void output_actions_for_process_1(T *result_process_1)
{
    int count_data = 0; // счетчик сколько данных из массива результатов было выведено, чтобы разделить их
    switch (count_data)
    {
        for (int i = n - 1; i >= 0; i--)
            if (result_process_1[i] != "|")
            {
                {
                case 0:
                    cout << "Number of negative elements \t" << arr[i] << endl;
                    count_data++;
                    break;
                case 1:
                    cout << "Sum of negative elements \t" << arr[i] << endl;
                    count_data++;
                    break;
                case 2:
                    cout << arr[i] << " ";
                    break;
                default:
                    break;
                }
                cout << " - coordinates of negative elements" << endl;
            }
    }
}

// ФУНКЦИИ ДЛЯ UI

// oчистка терминала
void clear_terminal()
{
    system("cls");
}

// задание 1
void screen_exercise_1_terminal()
{
    clear_terminal();
    int k = 0; // Номер оперцаии
    cout << "Select and enter the number of the operation you need" << endl;
    cout << "1 \t calculate the sum of negative elements of the array, determine their number and find their coordinates;" << endl;
    cout << "2 \t calculate the product of array elements located between the maximum and minimum element, indicating their position in the array;" << endl;
    cout << "3 \t sort array elements in ascending order" << endl;
    while (true)
    {
        cin >> k;
        switch (k)
        {
        case 1:
            process_1_terminal();
        case 2:
            break;
        case 3:
            break;
        default:
            cout << "Invalid operation number" << endl;
            break;
        }
    }
}

// функция для действия 1 задания 1 в терминале
void process_1_terminal()
{
    clear_terminal();
    input_dimension();
    double *arr = new double[n];
    arr = input_arr<double>();
    output_actions_for_process_1(actions_for_process_1(arr));
}

// функция для действия 2 задания 1 в терминале
void process_2_terminal()
{
}

// функция для действия 3 задания 1 в терминале
void process_3_terminal()
{
}

// функция для создания и работы с программой
void terminal_process()
{
    int k = 0; // Номер задания
    cout << "Welcome to the program!" << endl;
    cout << "select and enter the task number" << endl;
    cout << "1. Exercise 1" << endl;
    cout << "2. Exercise 2" << endl;
    cout << "3. Exercise 3" << endl;
    while (true)
    {
        cin >> k;
        switch (k)
        {
        case 1:
            screen_exercise_1_terminal();
        case 2:
            break;
        case 3:
            break;
        default:
            cout << "Invalid task number" << endl;
            break;
        }
    }
}

int main()
{
    terminal_process();
}