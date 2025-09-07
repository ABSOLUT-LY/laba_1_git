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
        int sentence_count = 0;     // колчиество предложений
        bool has_letters = false;   // Есть ли буквы в текущем предложении
        bool expect_capital = true; // Ожидаем заглавную букву в начале предложения

        for (int i = 0; str[i] != '\0'; i++)
        {
            char c = str[i];

            if (isalpha(c)) // если буква
            {
                if (expect_capital && islower(c)) // если мы ожидаем загавную, а текущая букува маленькая
                {
                    return false; // Предложение должно начинаться с заглавной
                }
                has_letters = true;     // иначе мы нашли букву - они есть
                expect_capital = false; // не ожидаем заглавную букву т.к она была только что
            }
            else if ((c == '!' || c == '?' || c == '.') && has_letters) // если знак конца предложеня и предложение содержало буквы
            {
                // Корректное окончание предложения
                sentence_count++;      // +1 предложение
                has_letters = false;   // обнуляем флаги
                expect_capital = true; // снова ждем заглавную

                // Пропускаем повторяющиеся конечные символы
                while (str[i + 1] == '!' || str[i + 1] == '?' || str[i + 1] == '.') // если символы повторяюся
                {
                    i++; // просто идем дальше
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
        // если в строке не необходимое количество преложений
        if (!valid_count_sentences(str, Constants::MAX_COUNT_SENTENCES))
        {
            ConsoleUI::error_message_string(Error_string::COUNT_SENTENCES_ERROR);
            return false;
        }
        // если в строке не валидные символы
        if (!valid_symbols_in_string(str))
        {
            ConsoleUI::error_message_string(Error_string::SYMBOLS_ERROR);
            return false;
        }
        // иаче все корректно
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
};
