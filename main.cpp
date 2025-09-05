#include <iostream>
#include "common_constants.hpp" // импор для namespace contains
#include "console_ui.hpp"
#include "array_processor.hpp"
#include "data.hpp"

using namespace std;

class Application
{
public:
    // функция страта проекта
    void run()
    {
        terminal_process();
    }

private:
    ArrayProcessor processor;
    ConsoleUI ui;
    Data ex_1;

    // функция для действия 1 задания 1 в терминале
    void process_1_terminal()
    {
        ConsoleUI::clear_terminal();
        ex_1.get_validated_array_dimension();
        ConsoleUI::clear_terminal();
        ex_1.get_validated_array();
        // ConsoleUI::clear_terminal();
        ex_1.output_actions_for_process_1(ex_1.get_arr());
        ConsoleUI::homescreen_message();
    }

    // функция для действия 2 задания 1 в терминале
    void process_2_terminal()
    {
    }

    // функция для действия 3 задания 1 в терминале
    void process_3_terminal()
    {
    }

    // задание 1
    void screen_exercise_1_terminal()
    {
        ConsoleUI::clear_terminal();
        int k = 0; // Номер оперцаии
        ConsoleUI::message_exercise_1_screen();
        while (true)
        {
            cin >> k;
            switch (k)
            {
            case 1:
                process_1_terminal();
                return;
            case 2:
                return;
            case 3:
                return;
            default:
                cout << "Invalid operation number. Try again:" << "\t";
                break;
            }
        }
    }

    // создание начального экрана
    void terminal_process()
    {
        int k = 0; // Номер задания
        ConsoleUI::message_homescreen();
        while (true)
        {
            cin >> k;
            switch (k)
            {
            case 1:
                screen_exercise_1_terminal();
                terminal_process();
                break;
            case 2:
                break;
            case 3:
                break;
            default:
                cout << "Invalid operation number. Try again:" << "\t";
                break;
            }
        }
    }
};

int main()
{
    Application app;
    app.run();
    return 0;
}
