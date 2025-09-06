#pragma once

// ФАЙЛ С ТИПАМИ ОШИБОК

// enum определяет набор именованных констант, которые имеют числовые значения по умолчнию
// !предоставляет выбор вариатнов!

// ДЛЯ МАССИВОВ
enum class Error_dimension
{
    BUFF_ERROR,   // 0 - сумма
    SORT_ERROR,   // 1 - сортиоровка
    SUM_ERROR,    // 1 - сортиоровка
    PRODUCT_ERROR // 2 - произведение
};

// ДЛЯ СТРОК
enum class Error_string
{
    SYMBOLS_ERROR,         // 0 - ошибка символов
    COUNT_SENTENCES_ERROR, // 1 - ошибка количетсва предложений
};

// ДЛЯ ФАЙЛОВ
enum class Error_file
{
    FILE_DOES_NOT_EXIST, // 0 - файл не сущетсвует
    FILE_NAME_ERROR,     // 1 - ошибка имени файла
};
