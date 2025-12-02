#ifndef __ERROR_MESSAGES_H__
#define __ERROR_MESSAGES_H__

void syntax_error_CLI(const char * message);
void error_CLI();

void file_error_CNV(const char * message, const char * filename);
void use_error_CNV();
void syntax_error_CNV(long position);
void error_CNV();

#endif