#include "cli_manager.h"
#include "error_messages.h"
#include <string.h>
#include <stdio.h>

const char *commands[3] ={
    //help
    "-h",
    //to hex file
    "-x",
    //to bin file
    "-b"
};

enum command read_command(char * command){
    for(enum command i = 0; i < UNKNOWN; i++){
        if(strcmp(commands[i], command) == 0){
            return i;
        }
    }
    return UNKNOWN;
}

int read_cli(int argc, char *argv[], struct programm_usage * usage){
    if(argc < 2){
        syntax_error_CLI("Not enough arguments");
        return 0;
    }
    enum command cmd = read_command(argv[1]);
    usage->cmd = cmd;
    usage->filename = 0;
    if(cmd == HELP){
        return 1;
    }
    if(cmd == TO_BIN || cmd == TO_HEX){
        if(argc < 3){
            syntax_error_CLI("Not enough arguments for this command");
            return 0;
        }
        usage->filename = argv[2];
    }else{
        syntax_error_CLI("Unknown command");
        return 0;
    }
    return 1;
}