#include <stdio.h>
#include "error_messages.h"
#include "cli_manager.h"
#include "converter.h"

int main(int argc, char *argv[]){
    struct program_usage usage;
    if(!read_cli(argc, argv, &usage)){ 
        error_CLI();
        return 1;
    }
    if(usage.cmd == HELP){
        printf("Usage: converter (-x | -b) <input_file>\n\n");
        printf("Convert between ASCII HEX and binary file formats.\n\n");
        printf("Options:\n");
        printf(" -x\tConvert BIN file to HEX\n");
        printf(" -b\tConvert HEX file to BIN\n");
        printf(" -h\tDisplay this help message\n\n");
        printf("Examples:\n");
        printf(" converter -x data.bin\t# Creates data.bin.hex from binary file\n");
        printf(" converter -b data.hex\t# Creates data.hex.bin from hex file\n\n");
        printf("Input format for HEX files: ASCII hexadecimal characters (0-9, a-f, A-F)\n");
        printf("Output files are automatically named by appending .hex or .bin extension.\n");
    }else{ 
        if(!convert_file(usage)){
            error_CNV();
            return 1;
        }
    }
    return 0;
}