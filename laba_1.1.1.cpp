#include <iostream>

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
T *input_arr(T *arr)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    return arr;
}

// ввод ращмерности массива
void input_dimension(){
    cout << "Enter the array dimension:" << "/t";
    cin >> n;
    cout << endl << "Array created";
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
        error_message_negative_count();
        return false;
    }
    return true;
}

// функция нахождения суммы отрицательных элементов
template <typename T>
T sum_arr(T *arr)
{
    T sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            sum += arr[i];
        }
    }
    return sum;
}


// ФУНКЦИИ ДЛЯ 

int main()
{
    input_dimension();
    double* arr = new double [n];

    delete arr;
}