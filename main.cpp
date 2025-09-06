#include <iostream>               // ввыод/вывод
#include "common_constants.hpp"   // импор для namespace contains
#include "console_ui.hpp"         // импорт для работы с консольным интерфейсом
#include "array_processor.hpp"    // импорт для проверки данных на валидность
#include "data_array_worker.hpp"  // класс для работы с массивами
#include "data_file_worker.hpp"   // класс для работы с фалами
#include "data_string_worker.hpp" // класс для работы с строками
#include "string_processor.hpp"   // класс для проверки валдности строк

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
        ConsoleUI::clear_terminal();                                   // очищаем терминал перед работой
        ConsoleUI::message_input_dimension_array();                    // вывод собщения о вводе размерности
        ex_1.get_validated_array_dimension_for_sum();                  // вызывает ввод размерности массива для экземпляра класса.Д
        ConsoleUI::clear_terminal();                                   // очищаем терминал для следующего сообщения
        ConsoleUI::message_input_array_elements();                     // вывод сообщщения о вводе элементов массива
        ex_1.get_validated_array_for_sum();                            // вызывае тввод элементов массива для экхемпляра класса
        double *result = ex_1.calculate_result_for_process_1();        // высчитываем результат действия первого: или массив или nullptr
        if (ArrayProcessor::valid_result_for_output_process_1(result)) // проверяем на валидность если массив - валидно
        {
            ConsoleUI::output_res_process_1(result, ex_1.get_negative_count()); // вызов функции консоли для вывода результата
            ConsoleUI::want_to_homescreen_message_dialog();                     // диалог о возврщении на главный экран
        }
        else
        {
            ConsoleUI::error_message_negative_count_lower_than_two(); // сообщение о ошибке данных массива
            ConsoleUI::want_to_homescreen_message_dialog();           // диалог о возвращении на главный экран
            // деструктор будет вызван автоматически при выходе из блока кода
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
        ConsoleUI::clear_terminal();                              // очищаем терминал перед работой
        ConsoleUI::message_input_dimension_array();               // вывод собщения о вводе размерности
        ex_1.get_validated_array_dimension_for_sort();            // вызывает ввод размерности массива для экземпляра класса
        ConsoleUI::clear_terminal();                              // очищаем терминал для следующего сообщения
        ConsoleUI::message_input_array_elements();                // вывод сообщщения о вводе элементов массива
        ex_1.get_validated_array_for_sort();                      // вызывае тввод элементов массива для экхемпляра класса
        double *result = ex_1.sort_array();                       // высчитываем результат действия первого: или массив или nullptr
        ConsoleUI::output_res_process_2(result, ex_1.get_size()); // вызов функции консоли для вывода результата
        ConsoleUI::want_to_homescreen_message_dialog();           // диалог о возврщении на главный экран
        // деструктор будет вызван автоматически при выходе из блока кода
    }

    // задание 1
    void screen_exercise_1_terminal() // экран выбора действия в задании 1
    {
        ConsoleUI::clear_terminal();            // очистка терминала перед началом работы
        int k = 0;                              // Номер оперцаии
        ConsoleUI::message_exercise_1_screen(); // вывод сообщений с возможными действиями
        while (true)                            // бесконечный цикл для возможности многократного ввода пользователем
        {
            cin >> k; // ввод номера действия
            switch (k)
            {
            case 1:                   // к == 1 действие 1
                process_1_terminal(); // запуск действия 1
                return;               // выход из While и switch - конец выполнения функции
            case 2:                   // к == 2 действие 2
                /*ЗДЕСЬ ПОТОМ ДАПИСАТЬ ВТОРОЕ ДЕЙСТВИЕ*/
                return;                                              // выход из While и switch - конец выполнения функции
            case 3:                                                  // к == 3 - действие 3
                process_3_terminal();                                // запуск действия 3
                return;                                              // выход из While и switch - конец выполнения функции
            default:                                                 // Нет такого действия
                ConsoleUI::error_message_invalid_operation_number(); // вывод сообщения о ошибке номера операции
                break;                                               // выход из switch и вход назад в while
            }
        }
    }

    // задание 3
    void screen_exercise_3_terminal() // экран выбора действия в задании 3
    {
        ConsoleUI::clear_terminal(); // очистка терминала перед началом работы
        ConsoleUI::message_input_name_file();
        f_3.get_file_name();
        ConsoleUI::clear_terminal();
        char *text = f_3.read_file();
        if (FileProcessor::valid_result_of_read_file(text))
        {
            str_3.get_validated_string(text);
            char *result = str_3.reverse_string();
            if (StringProcessor::valid_output_of_exercise_3(result))
            {
                ConsoleUI::output_res_exercise_3(result);
                ConsoleUI::want_to_homescreen_message_dialog(); // диалог о возврщении на главный экран
            }
            else
            {
                ConsoleUI::error_result_exercise_3_message();
                ConsoleUI::want_to_homescreen_message_dialog(); // диалог о возвращении на главный экран
            }
        }
        else
        {
            ConsoleUI::error_file_message(Error_file::FILE_DOES_NOT_EXIST);
            ConsoleUI::want_to_homescreen_message_dialog(); // диалог о возврщении на главный экран
        }
    }

    // создание начального экрана
    void terminal_process()
    {
        int k = 0;                       // Номер задания
        ConsoleUI::message_homescreen(); // Ввывод сообщния дял выбора пользователем действия
        while (true)                     // бесконечный цикл для возможности многократного ввода пользователем
        {
            cin >> k; // ввод номера действия
            switch (k)
            {
            case 1:                                                  // к == 1 действие 1
                screen_exercise_1_terminal();                        // отображение меню действия 1
                terminal_process();                                  // после окончания работы действия 1 и диалога возврата на главный экран, если не выборал "N\n"
                break;                                               // выход из свитч
            case 2:                                                  // к == 2 действие 2
                break;                                               // выход из свитч
            case 3:                                                  // к == 3 действие 3
                screen_exercise_3_terminal();                        // отображение меню действия 1
                terminal_process();                                  // после окончания работы действия 1 и диалога возврата на главный экран, если не выборал "N\n"
                break;                                               // выход из свитч
            default:                                                 // Нет такого варианта
                ConsoleUI::error_message_invalid_operation_number(); // вывод сообщения о ошибке номера операции
                break;                                               // выход из свитч
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
