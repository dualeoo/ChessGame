#include <string.h>
#include <stdlib.h>
#include "String.h"

struct String *StringIni(char *string_p) {
    size_t size = strlen(string_p);
    struct String *string = malloc(sizeof(struct String) + (size + 1) * sizeof(char));
//    string->string = calloc(size + 1, sizeof(char));
    string->size = size;
    strncpy(string->string, string_p, size);
    return string;
}

