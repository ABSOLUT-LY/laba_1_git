#include <iostream>

#ifndef EXERCISE_1
#define EXERCISE_1

#define MAX_BUFF 200
// Изименить расширение на .h. Добавить в начале файла
// #ifndef simple_name
// #define simple_name
// И в конце
// #endif – для закрытия #ifndef

using namespace std;

// класс для задания 1
class Exercise_1
{
    // поле доступное всем
public:
    // конструткор класса
    // Exercise_1(int n)
    // {
    //     (*this).n = n;
    // }

    // деструктор класса
    ~Exercise_1()
    {
        delete arr;
    }

    // ФУНКЦИИ ДЛЯ ВВОДА

    // функция ввода массива если бы она была вне класса
    // template <typename T>
    // T *input_arr()
    // {
    //     T *arr = new T[this->n];
    //     for (int i = 0; i < this->n; i++)
    //     {
    //         cin >> arr[i];
    //     }
    //     return arr;
    // }

    // ФУНКЦИИ ДЛЯ ВЫВОДА РЕЗУЛЬТАТОВ РАБОТЫ ПРОЦЕССОВ
    void output_actions_for_process_1()
    {
        double *result_process_1 = this->actions_for_process_1();

        if (result_process_1 == nullptr)
        {
            cout << "Operation failed: no negative elements found." << endl;
            return; // Прерываем выполнение
        }

        // Вывод количества отрицательных элементов
        cout << "Number of negative elements \t" << result_process_1[this->negative_count] << endl;

        // Вывод суммы отрицательных элементов
        cout << "Sum of negative elements \t" << result_process_1[this->negative_count + 1] << endl;

        // Вывод элементов массива
        cout << "Index of negative array elements: ";
        for (int i = 0; i < this->negative_count; i++)
        {
            cout << result_process_1[i] << " ";
        }
        cout << endl;
        delete[] result_process_1;
    }

    // ФУНКЦИИ ДЛЯ ВВОДА ДАННЫХ

    // функция для ввода массива в классе
    void input_arr()
    {
        this->arr = new double[this->n];
        cout << "Enter the array elements (separated by enter):" << endl;
        for (int i = 0; i < this->n; i++)
        {
            cin >> this->arr[i];
        }
        cout << "Array created" << endl;
    }

    // ввод ращмерности массива и проверка его на соответсвие буферу (надо как тоее под класс подогнать)
    void input_dimension()
    {
        cout << "Enter the array dimension (no more than " << MAX_BUFF << ")" << endl;
        cin >> this->n;
        while (true)
        {
            if (n > MAX_BUFF)
            {
                cout << "dimension greater than " << MAX_BUFF << " .Try again." << endl;
                cin >> this->n;
            }
            else if (n < 2)
            {
                cout << "dimension lower than 2" << " .Try again." << endl;
                cin >> this->n;
            }
            else
            {
                cout << "Сorrectly" << endl;
                break;
            }
        }
    }

    // поле доступное только в классе
private:
    // поля класса доступные только из него
    int n;
    double *arr;
    int negative_count; // дял понимания ращмерности выходного массива


    // ФУНКЦИИ ДЛЯ РАБОТЫ С ДАННЫМИ

    // функция проверки массива на валидность для суммы отрицательных чисел перед началом работы
    bool valid_for_negative_sum()
    {
        int negative_count = 0;
        for (int i = 0; i < this->n; i++)
        {
            if (this->arr[i] < 0)
            {
                negative_count++;
            }
        }
        if (not(negative_count))
        {
            error_message_negative_count(negative_count);
            return false;
        }
        if (negative_count < 2)
        {
            error_message_negative_count_lower_then_two();
            return false;
        }
        return true;
    }

    // функция нахождения суммы, индексов и колчества отрицательных элементов
    double *actions_for_process_1()
    {
        if (valid_for_negative_sum())
        {
            double sum = 0;
            int count_negative = 0;
            for (int i = 0; i < this->n; i++)
            {
                if (this->arr[i] < 0)
                {
                    count_negative++;
                    sum += arr[i];
                }
            }
            double *res = new double[count_negative + 2];
            int counter = 0; // счётчик количества элементов массива res
            for (int i = 0; i < this->n; i++)
            {
                if (this->arr[i] < 0)
                {
                    res[counter] = i;
                    counter++;
                }
            }
            res[counter] = sum;
            res[counter + 1] = count_negative;
            this->negative_count = count_negative;
            return res;
        }
        else
        {
            return nullptr;
        }
    }

    // поле доступное только в классе и потомкам (пока не юзаю - нет нужды)
protected:
};

#endif // EXERCISE_1
