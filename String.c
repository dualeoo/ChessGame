#include <string.h>
#include <stdlib.h>
#include "String.h"
#include "Helper.h"


struct String *StringIni(char *string_p) {
    size_t size = strlen(string_p);
    struct String *string = malloc(sizeof(struct String) + (size + 1) * sizeof(char));
//    TOFREEX
//    string->string = calloc(size + 1, sizeof(char));
    string->size = size;
    strncpy(string->string, string_p, size);
    return string;
}

int free_string(struct String *string, struct ArrayList *memory_which_has_been_free) {
    char contain = 0;
    memory_which_has_been_free->al_search(memory_which_has_been_free, string, &contain);
    if (!contain) {
        free(string);
        memory_which_has_been_free->al_insert(memory_which_has_been_free, -1, string);
    }
    return SUCCESS;
}

