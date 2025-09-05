#include <iostream>             // ввыод/вывод
#include "common_constants.hpp" // импор для namespace contains
#include "console_ui.hpp"       // импорт для работы с консольным интерфейсом
#include "array_processor.hpp"  // импорт для проверки данных на валидность
#include "data.hpp"             // класс для работы с данными

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

    Data ex_1; // экземпляр класса для возможности работать с его полями и методами

    // функция для действия 1 задания 1 в терминале
    void process_1_terminal()
    {
        ConsoleUI::clear_terminal();                                   // очищаем терминал перед работой
        ConsoleUI::message_input_dimension_array();                    // вывод собщения о вводе размерности
        ex_1.get_validated_array_dimension();                          // вызывает ввод размерности массива для экземпляра класса.Д
        ConsoleUI::clear_terminal();                                   // очищаем терминал для следующего сообщения
        ConsoleUI::message_input_array_elements();                     // вывод сообщщения о вводе элементов массива
        ex_1.get_validated_array();                                    // вызывае тввод элементов массива для экхемпляра класса
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
                return; // выход из While и switch - конец выполнения функции
            case 3:     // к == 3 - действие 3
                /*ЗДЕСЬ ПОТОМ ДАПИСАТЬ ТРЕТЬЕ ДЕЙСТВИЕ*/
                return;                                              // выход из While и switch - конец выполнения функции
            default:                                                 // Нет такого действия
                ConsoleUI::error_message_invalid_operation_number(); // вывод сообщения о ошибке номера операции
                break;                                               // выход из switch и вход назад в while
            }
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
