#include "common_constants.hpp" // импор для namespace contains
#include "error_type.hpp"       // для ValidationType
#include "console_ui.hpp"       // Для вывода сообщений в консоль
#pragma once
/*Статические методы - можно использовать без экзмепляра класса и не имеют доступа к this*/

/*Здесь хранятся только логика для проверки данных строк*/
class StringProcessor
{
public:
    // проверка что в строке три предложения
    static bool valid_count_sentences(char *str, int count_sentences)
    {
        if (str == nullptr)
        {
            return false;
        }
        int sentence_count = 0;
        bool has_letters = false;   // Есть ли буквы в текущем предложении
        bool expect_capital = true; // Ожидаем заглавную букву в начале предложения

        for (int i = 0; str[i] != '\0'; i++)
        {
            char c = str[i];

            if (isalpha(c))
            {
                if (expect_capital && islower(c))
                {
                    return false; // Предложение должно начинаться с заглавной
                }
                has_letters = true;
                expect_capital = false;
            }
            else if ((c == '!' || c == '?' || c == '.') && has_letters)
            {
                // Корректное окончание предложения
                sentence_count++;
                has_letters = false;
                expect_capital = true;

                // Пропускаем повторяющиеся конечные символы
                while (str[i + 1] == '!' || str[i + 1] == '?' || str[i + 1] == '.')
                {
                    i++;
                }
            }
        }

        // Если строка закончилась без конечного символа, но есть буквы
        if (has_letters)
        {
            sentence_count++;
        }

        return sentence_count == count_sentences;
    }

    // проврека что строка из допустимых символов
    static bool valid_symbols_in_string(char *str)
    {
        if (str == nullptr)
        {
            return false;
        }
        for (int i = 0; str[i] != '\0'; i++)
        {
            char c = str[i];
            if (isalpha(c) || isspace(c) || isdigit(c) || c == '!' || c == '?' || c == '.')
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    // проверка что строка полностью валидна
    static bool valid_string(char *str)
    {
        if (!valid_count_sentences(str, Constants::MAX_COUNT_SENTENCES))
        {
            ConsoleUI::error_message_string(Error_string::COUNT_SENTENCES_ERROR);
            return false;
        }
        if (!valid_symbols_in_string(str))
        {
            ConsoleUI::error_message_string(Error_string::SYMBOLS_ERROR);
            return false;
        }
        return true;
    }

    // проверка что резултат для вывода корректен
    static bool valid_output_of_exercise_3(char *str)
    {
        if (str == nullptr)
        {
            return false;
        }
        return true;
    }


    // проверка корректности работы 
};
