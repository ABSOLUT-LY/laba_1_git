#include <iostream>                   // ввыод/вывод
#include "common_constants.hpp"       // импор для namespace contains
#include "console_ui.hpp"             // импорт для работы с консольным интерфейсом
#include "array_processor.hpp"        // импорт для проверки данных на валидность
#include "data_array_worker.hpp"      // класс для работы с массивами
#include "data_file_worker.hpp"       // класс для работы с фалами
#include "data_string_worker.hpp"     // класс для работы с строками
#include "string_processor.hpp"       // класс для проверки валдности строк
#include "error_type.hpp"             // класс с типами ошибок
#include "screen_console_options.hpp" //для вариантов выбора сообщений

using namespace std; // для доступа к функциям из std без написания std::

class Application // класс, управляющий логикой всей программы
{
public: // методы доступные вне класса, для его экземпляров
    // функция запуска проекта
    void run()
    {
        terminal_process(); // запуск процесса терминала (начальный экран)
    }

private: // методы доступные внутри класса
    /* ArrayProcessor processor; создание этих экземпляров классов не является необходимым
    ConsoleUI ui;                так как используются тольк остатические методы
                                (которым не нужен экемпляр)*/

    Data_array_worker ex_1;   // экземпляр класса для возможности работать с его полями и методами
    Data_file_worker f_3;     // экземпляр класса для задания 3 - хранит в себе имя файла пользователя
    Data_string_worker str_3; // экземпляр класса для задания 3 - хранит в себе содержимое фала пользхователя

    // функция для действия 1 задания 1 в терминале
    void process_1_terminal()
    {
        ConsoleUI::clear_terminal();                                       // очищаем терминал перед работой
        ConsoleUI::handler_screen_exercise_1(Exercise_1::DIMENSION_INPUT); // вывод собщения о вводе размерности
        while (true)                                                       // пока ввод размерности не будет правильным
        {
            try
            {
                ex_1.get_validated_array_dimension_for_sum(); // вызывает ввод размерности массива для экземпляра класса
                break;
            }
            catch (const std::invalid_argument &e)
            {
                ConsoleUI::handler_error_message_dimension(Error_dimension::SUM_ERROR);
                continue;
            }
        }
        ConsoleUI::clear_terminal();                                   // очищаем терминал для следующего сообщения
        ConsoleUI::handler_screen_exercise_1(Exercise_1::ARRAY_INPUT); // вывод сообщщения о вводе элементов массива
        ex_1.get_validated_array_for_sum();                            // вызывае тввод элементов массива для экхемпляра класса
        try
        {
            double *result = ex_1.calculate_result_for_process_1();             // высчитываем результат действия первого: или массив или nullptr
            ConsoleUI::output_res_process_1(result, ex_1.get_negative_count()); // вызов функции консоли для вывода результата
            ConsoleUI::handler_screen_programm(AppOptions::HOMESCREEN_DIALOG);  // диалог о возврщении на главный экран
        }
        catch (const std::invalid_argument &e)
        {
            ConsoleUI::handler_error_message_array_elements(Error_array_content::ERROR_COUNT_NEGATIVE_ELEMENTS_FOR_SUM); // сообщение о ошибке данных массива
            ConsoleUI::handler_screen_programm(AppOptions::HOMESCREEN_DIALOG);                                           // диалог о возвращении на главный экран                                                           // деструктор будет вызван автоматически при выходе из блока кода
        }
        catch (const std::exception &e)
        {
            ConsoleUI::handler_error_main_app(App_error::UNKNOWN_ERROR);       // сообщение о ошибке данных массива
            ConsoleUI::handler_screen_programm(AppOptions::HOMESCREEN_DIALOG); // диалог о возвращении на главный экран
        }
    }

    // функция для действия 2 задания 1 в терминале
    void process_2_terminal()
    {
        /*ЗАХАР ВОТ ТУТ ТЕБЕ НАДО БУДЕТ ПИСАТЬ*/
    }

    // функция для действия 3 задания 1 в терминале
    void process_3_terminal()
    {
        ConsoleUI::clear_terminal();                                       // очищаем терминал перед работой
        ConsoleUI::handler_screen_exercise_1(Exercise_1::DIMENSION_INPUT); // вывод собщения о вводе размерности
        while (true)                                                       // пока ввод размерности не будет правильным
        {
            try
            {
                ex_1.get_validated_array_dimension_for_sort(); // вызывает ввод размерности массива для экземпляра класса
                break;
            }
            catch (const std::invalid_argument &e)
            {
                ConsoleUI::handler_error_message_dimension(Error_dimension::SORT_ERROR);
                continue;
            }
        }
        ConsoleUI::clear_terminal();                                       // очищаем терминал для следующего сообщения
        ConsoleUI::handler_screen_exercise_1(Exercise_1::ARRAY_INPUT);     // вывод сообщщения о вводе элементов массива
        ex_1.get_validated_array_for_sort();                               // вызывае тввод элементов массива для экхемпляра класса
        double *result = ex_1.sort_array();                                // высчитываем результат действия первого: или массив или nullptr
        ConsoleUI::output_res_process_3(result, ex_1.get_size());          // вызов функции консоли для вывода результата
        ConsoleUI::handler_screen_programm(AppOptions::HOMESCREEN_DIALOG); // диалог о возврщении на главный экран
        // деструктор будет вызван автоматически при выходе из блока кода
    }

    // задание 1
    void screen_exercise_1_terminal() // экран выбора действия в задании 1
    {
        ConsoleUI::clear_terminal();                          // очистка терминала перед началом работы
        int k = 0;                                            // Номер оперцаии
        ConsoleUI::handler_screen_programm(AppOptions::EX_1); // вывод сообщений с возможными действиями
        while (true)                                          // бесконечный цикл для возможности многократного ввода пользователем
        {
            cin >> k; // ввод номера действия
            switch (k)
            {
            case 1:                   // к == 1 действие 1
                process_1_terminal(); // запуск действия 1
                return;               // выход из While и switch - конец выполнения функции
            case 2:                   // к == 2 действие 2
                /*ЗДЕСЬ ПОТОМ ДАПИСАТЬ ВТОРОЕ ДЕЙСТВИЕ*/
                return;                                                                 // выход из While и switch - конец выполнения функции
            case 3:                                                                     // к == 3 - действие 3
                process_3_terminal();                                                   // запуск действия 3
                return;                                                                 // выход из While и switch - конец выполнения функции
            default:                                                                    // Нет такого действия
                ConsoleUI::handler_error_main_app(App_error::INVALID_OPERATION_NUMBER); // вывод сообщения о ошибке номера операции
                break;                                                                  // выход из switch и вход назад в while
            }
        }
    }

    // задание 3
    void screen_exercise_3_terminal() // экран выбора действия в задании 3
    {
        ConsoleUI::clear_terminal();                                 // очистка терминала перед началом работы
        ConsoleUI::handler_screen_exercise_3(Exercise_3::FILE_NAME); // ввод имени файла
        f_3.get_file_name();                                         // получение имени файла классом файла
        ConsoleUI::clear_terminal();                                 // очистка терминала перед началом работы
        try
        {
            char *text = f_3.read_file(); // чтение из файла
            try
            {
                str_3.get_validated_string(text);                                  // присваиваем к классу строки
                char *result = str_3.reverse_string();                             // выполняем операцию задания
                ConsoleUI::output_res_exercise_3(result);                          // выводим результат
                ConsoleUI::handler_screen_programm(AppOptions::HOMESCREEN_DIALOG); // диалог о возврщении на главный экран
            }
            catch (const std::invalid_argument &e)
            {
                ConsoleUI::handler_error_messge_string_content(Error_string::CONTENT_STRING_ERROR); // если файла нет - пишем, что нет
                ConsoleUI::handler_screen_programm(AppOptions::HOMESCREEN_DIALOG);                  // диалог о возврщении на главный экран
            }
            catch (const std::exception &e)
            {
                ConsoleUI::handler_error_main_app(App_error::UNKNOWN_ERROR);       // сообщение о ошибке данных массива
                ConsoleUI::handler_screen_programm(AppOptions::HOMESCREEN_DIALOG); // диалог о возвращении на главный экран
            }
        }
        catch (const std::invalid_argument &e)
        {
            ConsoleUI::handler_error_file_message(Error_file::FILE_DOES_NOT_EXIST); // если файла нет - пишем, что нет
            ConsoleUI::handler_screen_programm(AppOptions::HOMESCREEN_DIALOG);      // диалог о возврщении на главный экран
        }
        catch (const std::exception &e)
        {
            ConsoleUI::handler_error_main_app(App_error::UNKNOWN_ERROR);       // сообщение о ошибке данных массива
            ConsoleUI::handler_screen_programm(AppOptions::HOMESCREEN_DIALOG); // диалог о возвращении на главный экран
        }
    }

    // создание начального экрана
    void terminal_process()
    {
        int k = 0;                                                  // Номер задания
        ConsoleUI::handler_screen_programm(AppOptions::HOMESCREEN); // Ввывод сообщния дял выбора пользователем действия
        while (true)                                                // бесконечный цикл для возможности многократного ввода пользователем
        {
            cin >> k; // ввод номера действия
            switch (k)
            {
            case 1:                                                                     // к == 1 действие 1
                screen_exercise_1_terminal();                                           // отображение меню действия 1
                terminal_process();                                                     // после окончания работы действия 1 и диалога возврата на главный экран, если не выборал "N\n"
                break;                                                                  // выход из свитч
            case 2:                                                                     // к == 2 действие 2
                break;                                                                  // выход из свитч
            case 3:                                                                     // к == 3 действие 3
                screen_exercise_3_terminal();                                           // отображение меню действия 1
                terminal_process();                                                     // после окончания работы действия 1 и диалога возврата на главный экран, если не выборал "N\n"
                break;                                                                  // выход из свитч
            default:                                                                    // Нет такого варианта
                ConsoleUI::handler_error_main_app(App_error::INVALID_OPERATION_NUMBER); // вывод сообщения о ошибке номера операции
                break;                                                                  // выход из свитч
            }
        }
    }
};

int main() // главная функция
{
    Application app; // создание экземпляра класса
    app.run();       //  запуск экземпляра
    return 0;        // так как int main()
}
