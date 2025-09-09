#include <fstream>              // для работы с файлами
#include "common_constants.hpp" // для констант
#include <istream>              // для getline
#include "console_ui.hpp"       // для данных с консоли
#include "file_processor.hpp"   // для валидации

#pragma once

// класс для работы с файлами
class Data_file_worker
{
private:
    char *name = new char[Constants::MAX_BUFF_STRING]; // имя файла

public:
    Data_file_worker() : name(nullptr) {}; // конструктор
    ~Data_file_worker()                    // деструктор
    {
        delete[] name; // очистка памяти
    }

    // чтение из файла
    char *read_file()
    {
        char *tmp = new char[Constants::MAX_BUFF_STRING]; // создаем строку
        std::ifstream file(this->name);                   // инициализируем файл для вывода
        if (FileProcessor::valid_file_exists(file))       // проверка на валиность файла
        {
            file.getline(tmp, Constants::MAX_BUFF_STRING); // чтение строки из файла
            file.close();                                  // закрытие файла
            return tmp;                                    // выходим
        }
        file.close(); // закрытие файла
        delete[] tmp; // очистка памяти
        throw std::invalid_argument("error filename");
    }

    // очистка файла
    void clear_file()
    {
        std::fstream file(this->name);              // открываем файл для ввода
        if (FileProcessor::valid_file_exists(file)) // если файл валиден
        {
            file.open(this->name, std::ios::out | std::ios::trunc); // Очситка файла
            file.close();                                           // закрываем файл
        }
        return; // выходим
    }

    // ввод имени файла
    void get_file_name()
    {
        char *tmp = ConsoleUI::get_file_name();  // записываем имя файла в временную переменную
        if (FileProcessor::valid_file_name(tmp)) // если валидно - присваиваем
        {
            delete[] this->name;
            this->name = tmp;
            return;
        }
        delete[] tmp; // иначе - отпускаем
        this->name = nullptr;
        throw std::invalid_argument("filename error");
    }
};
