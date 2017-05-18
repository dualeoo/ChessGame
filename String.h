//
// Created by dualeoo on 30/4/17.
//
#ifndef CHESS_STRING_H
#define CHESS_STRING_H

#include "ArrayList.h"
struct String {
    size_t size;
    char string[1];

};

struct String *StringIni(char *);

int free_string(struct String *string, struct ArrayList *memory_which_has_been_free);

#endif
