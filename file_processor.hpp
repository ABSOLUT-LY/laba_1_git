#include "common_constants.hpp" // импор для namespace contains
#include "error_type.hpp"       // для ValidationType
#include "console_ui.hpp"       // Для вывода сообщений в консоль
#include <fstream>              // для работы с файлами

#pragma once

/*Статические методы - можно использовать без экзмепляра класса и не имеют доступа к this*/

/*Здесь хранятся только логика для проверки файлов*/
class FileProcessor
{
public:
    // проверка что файлна вывод существует
    static bool valid_file_exists(std::ofstream &file)
    {
        if (file.is_open())
        {
            return true;
        }
        ConsoleUI::handler_error_file_message(Error_file::FILE_DOES_NOT_EXIST);
        return false;
    }

    // проверка что файл на ввод существует
    static bool valid_file_exists(std::ifstream &file)
    {
        if (file.is_open())
        {
            return true;
        }
        return false;
    }

    // проверка что файл на ввод/вывод существует
    static bool valid_file_exists(std::fstream &file)
    {
        if (file.is_open())
        {
            return true;
        }
        ConsoleUI::handler_error_file_message(Error_file::FILE_DOES_NOT_EXIST);
        return false;
    }

    // проверка валидность имени файла
    static bool valid_file_name(const char *filename)
    {
        // Проверка на нулевой указатель или пустую строку
        if (filename == nullptr || filename[0] == '\0')
        {
            ConsoleUI::handler_error_file_message(Error_file::FILE_NAME_ERROR);
            return false;
        }

        int i = 0;
        while (filename[i] != '\0') // пока имя файла
        {
            char c = filename[i]; // присваиваем текущую букву

            // Проверка на запрещенные символы: <>:"/\|?*
            if (c == '<' || c == '>' || c == ':' || c == '"' ||
                c == '/' || c == '\\' || c == '|' || c == '?' || c == '*')
            {
                ConsoleUI::handler_error_file_message(Error_file::FILE_NAME_ERROR);
                return false;
            }

            // Проверка на пробелы и управляющие символы (ASCII < 32)
            if (c <= 32)
            {
                ConsoleUI::handler_error_file_message(Error_file::FILE_NAME_ERROR);
                return false;
            }

            // Проверка на английские буквы (A-Z, a-z), цифры (0-9) и разрешенные символы
            if (!((c >= 'A' && c <= 'Z') || // заглавные английские
                  (c >= 'a' && c <= 'z') || // строчные английские
                  (c >= '0' && c <= '9') || // цифры
                  c == '-' || c == '_' || c == '.'))
            { // разрешенные символы
                ConsoleUI::handler_error_file_message(Error_file::FILE_NAME_ERROR);
                return false;
            }

            i++;
        }
        return true;
    }

    // проврка корректности чтения из файла
    static bool valid_result_of_read_file(char *str)
    {
        if (str == nullptr)
        {
            return false;
        }
        return true;
    }
};