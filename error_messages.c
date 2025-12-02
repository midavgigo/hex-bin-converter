#include "error_messages.h"
#include <stdio.h>
#include <string.h>

void syntax_error_CLI(const char * message){
    fprintf(stderr, "Syntax error in command line arguments:\n\t%s\n", message);
}

void error_CLI(){
    fprintf(stderr, "Can't read command line arguments\n");
}

void use_error_CNV(){
    fprintf(stderr, "Unknown command for convertion\n");
}

void file_error_CNV(const char * message, const char * filename){
    fprintf(stderr, "Error with file \"%s\":\n\t%s\n", filename, message);
}

void syntax_error_CNV(long position){
    fprintf(stderr, "Error symbol at %d position\n", position);
}

void error_CNV(){
    fprintf(stderr, "Error in converting file\n");
}