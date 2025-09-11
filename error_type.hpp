#pragma once

// ФАЙЛ С ТИПАМИ ОШИБОК

// enum определяет набор именованных констант, которые имеют числовые значения по умолчнию
// !предоставляет выбор вариатнов!

// ДЛЯ МАССИВОВ
enum class Error_dimension_array
{
    SORT_ERROR,   // 1 - сортиоровка
    SUM_ERROR,    // 1 - сортиоровка
    PRODUCT_ERROR // 2 - произведение
};

// ДЛЯ СТРОК
enum class Error_string
{
    SYMBOLS_ERROR,         // 0 - ошибка символов
    CONTENT_STRING_ERROR,  // 1
    COUNT_SENTENCES_ERROR, // 2 - ошибка количетсва предложений
    STRING_EMPTY
};

// ДЛЯ ФАЙЛОВ
enum class Error_file
{
    FILE_DOES_NOT_EXIST, // 0 - файл не сущетсвует
    FILE_NAME_ERROR,     // 1 - ошибка имени файла
};

enum class Error_array_content
{
    ERROR_COUNT_NEGATIVE_ELEMENTS_FOR_SUM,
};

// ДЛЯ РЕЗУЛЬТАТОВ ОСНОВНОЙ ПРОГРАММЫ
enum class App_error
{
    // Общие ошибки ввода
    INVALID_OPERATION_NUMBER,
    UNKNOWN_ERROR,
};

enum class Error_dimension_matrix
{
    INVALID_ROW_COUNT,
    INVALID_COLUMN_COUNT
};

enum class Error_matrix
{
    INVALID_MATRIX_FOR_FIND_SUM,
    NO_ZEROS_ROWS
};
