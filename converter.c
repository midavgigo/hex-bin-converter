#include "converter.h"
#include "error_messages.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int convert_file(struct programm_usage usage){
    if(usage.cmd != TO_HEX && usage.cmd != TO_BIN){
        use_error_CNV();
        return 0;
    }
    FILE * reader = fopen(usage.filename, "r");
    if(reader == NULL){
        file_error_CNV("Can't open file", usage.filename);
        return 0;
    }
    char * outfile = malloc(strlen(usage.filename)+5);
    outfile[0] = '\0';
    strcat(outfile, usage.filename);
    if(usage.cmd == TO_HEX){
        strcat(outfile, ".hex");
    }else{
        strcat(outfile, ".bin");
    }
    FILE * writer = fopen(outfile, "w+");
    if(writer == NULL){
        file_error_CNV("Can't open file", outfile);
        free(outfile);
        fclose(reader);
        return 0;
    }
    char c;
    char odd = 0;
    while((c=getc(reader)) != EOF){
        if(usage.cmd == TO_BIN){
            char b;
            if(c >= '0' && c <= '9'){
                b = c-'0';
            }else if((c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f')){
                if (c >= 'a'){
                    c -= 'a'-'A';
                }
                b = c-'A';
            }else{
                syntax_error_CNV(ftell(writer));
                fclose(reader);
                fclose(writer);
                return 1;
            }
            if(odd == 0){
                b <<= 4;
                putc(b, writer);
            }else{
                fseek(writer, -1, SEEK_CUR);
                b += getc(writer);
                fseek(writer, -1, SEEK_CUR);
                putc(b, writer);
            }
            odd = (odd+1)%2;
        }else{
            char hex[] = "0123456789ABCDEF";
            char h = c >> 4;
            char l = c & 0x0F;
            putc(hex[h], writer);
            putc(hex[l], writer);
        }
    }

    fclose(reader);
    fclose(writer);
    return 1;
}