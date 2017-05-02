#include <string.h>
#include <stdlib.h>
#include "String.h"

struct String *StringIni(char *string_p) {
    size_t size = strlen(string_p);
    struct String *string = malloc(sizeof(struct String));
    string->string = calloc(size + 1, sizeof(char));
    strncpy(string->string, string_p, size);
    string->size = size;
    return string;
}

