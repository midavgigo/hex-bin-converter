#ifndef __CLI_MANAGER_H__
#define __CLI_MANAGER_H__
#include "usage.h"

//Парсит аргументы командной строки и записывает результат в usage
//Функция возвращает успешность операции
int read_cli(int argc, char *argv[], struct program_usage * usage);

#endif