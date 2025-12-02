#ifndef __USAGE_H__
#define __USAGE_H__

//Перечисление команд 
enum command{
    HELP = 0,
    TO_HEX,
    TO_BIN,
    UNKNOWN
};

//Использование программы
//При команде HELP путь к файлу нулевой
struct program_usage{
    enum command cmd;
    const char * filename;
};

#endif