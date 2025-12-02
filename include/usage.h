#ifndef __USAGE_H__
#define __USAGE_H__

enum command{
    HELP = 0,
    TO_HEX,
    TO_BIN,
    UNKNOWN
};

struct programm_usage{
    enum command cmd;
    const char * filename;
};

#endif