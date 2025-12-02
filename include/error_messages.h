#ifndef __ERROR_MESSAGES_H__
#define __ERROR_MESSAGES_H__

//Ошибка в синтаксисе командной строки
void syntax_error_CLI(const char * message);
//Ошибка в аргументах командной строки
void error_CLI();

//Ошибка при работе с файлом
void file_error_CNV(const char * message, const char * filename);
//Ошибка при использовании функции convert_file
void use_error_CNV();
//Наличие неизвестных символов в файле hex
void syntax_error_CNV(long position);
//Ошибка при конвертировании
void error_CNV();

#endif