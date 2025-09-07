#include "common_constants.hpp" // импорт для namespace contains
#include "string_processor.hpp" // импорт для проверки данных на валидность
#include "validation_type.hpp"  // для ValidationType
#include "console_ui.hpp"       // импорт для работы с консольным интерфейсом

#pragma once

// класс для работы со строками
class Data_string_worker
{
    // только внутри класса
private:
    char *str = new char[Constants::MAX_BUFF_STRING]; // создание строки размером с буфер

    // снаружи класса
public:
    Data_string_worker() : str(nullptr) {} // стандартный конструктор

    ~Data_string_worker() // деструктор
    {
        delete[] str; // очищаем память
    }

    //

    // получение валидной строки
    void get_validated_string(char *tmp)
    {
        if (StringProcessor::valid_string(tmp)) // проверяем ее на валидность
        {
            delete[] str;    // освобождаем память
            this->str = tmp; // присваиваем
            return;          // выходим
        }
        else
        {
            this->str = nullptr; // причаиваем nullptr елсли строка не прошла
            throw std::invalid_argument("Dont read string");
            return; // выходим
        }
    }

    int last_char_index(char *str)
    {
        int index = 0;                   // начальный индекс строки
        while (this->str[index] != '\0') // пока не конец
        {
            index++; // ++++++
        }
        return index; // возвращаем индекс последнего занчимого символа
    }

    char *reverse_string()
    {
        if (this->str == nullptr)
        {
            return nullptr;
        }
        int n = last_char_index(this->str);
        char *tmp = new char[n + 1];
        for (int i = 0; i <= n; i++)
        {
            tmp[i] = this->str[n - i - 1];
        }
        tmp[n] = '\0';
        return tmp;
    }
};
