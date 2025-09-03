#include <iostream>

using namespace std;

int n;

void error_message_zero_count(int zc)
{
    cout << "Ошибка, найдено " << zc << " нулей, ожидалось 2" << endl;
}

void error_message_zero_index(int zc)
{
    cout << "Ошибка, между нулями " << zc << " элемент(а), ожидалось 2 и более" << endl;
}

template <typename T>
bool valid(T *arr)
{
    int ind_zero = 0;
    int zero_count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0 && not(zero_count))
        {
            zero_count++;
            ind_zero = i;
        }
        else if (arr[i] == 0 && zero_count)
        {
            zero_count++;
            ind_zero = i - ind_zero;
        }
    }
    if (zero_count != 2 && ind_zero < 2)
    {
        error_message_zero_count(zero_count);
        error_message_zero_index(ind_zero);
        return false;
    }
    else
    {
        if (zero_count != 2)
        {
            error_message_zero_count(zero_count);
            return false;
        }
        if (ind_zero < 2)
        {
            error_message_zero_index(ind_zero);
            return false;
        }
    }
    return true;
}

template <typename T>
T *input_arr(T *arr)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    return arr;
}

template <typename T>
T sum_arr(T *arr)
{
    bool flag_zero = false;
    T sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            flag_zero = true;
        }
        if (arr[i] == 0 && flag_zero)
        {
            if (sum)
            {
                return sum;
            }
        }
        if (flag_zero)
        {
            sum += arr[i];
        }
    }
    return 0;
}

int main()
{
    cin >> n;
    int *arr = new int[n];
    input_arr(arr);
    if (not(valid(arr)))
    {
        return 0;
    }
    else
    {
        cout << sum_arr(arr);
        return 0;
    }
}