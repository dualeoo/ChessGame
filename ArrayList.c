#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include "ArrayList.h"

static unsigned int initial_capacity = 16;
enum ErrorCode {
    Success, NULLPointer
};

struct ArrayList *ArrayListInit() {
    struct ArrayList *array_list1 = malloc(sizeof(struct ArrayList));
    if (array_list1 == NULL)
        return NULL;
    array_list1->data = malloc(sizeof(void *) * initial_capacity);
    if (array_list1->data == NULL) return NULL;
    for (int i = 0; i < initial_capacity; ++i) {
        array_list1->data[i] = 0;
    }
    array_list1->logical_size = 0;
    array_list1->capacity = initial_capacity;
    array_list1->al_insert = &al_insert;
    array_list1->al_remove = &al_remove;
    array_list1->al_search = &al_search;
    return array_list1;
}

bool al_insert(struct ArrayList *list, int position, void *value) {
    bool still_have_space = true;
    int error = check_capacity(list, &still_have_space);
    if (error) {
        printf("NULL pointer error!\n");
        return false;
    }
    if (!still_have_space) {
        list->capacity *= 2;
        void **temp = list->data;
        list->data = malloc(list->capacity);
        memcpy(list->data, temp, list->logical_size);
        free(temp);
    }
    if (position == list->logical_size || position == -1) {
        list->data[list->logical_size] = value;
    } else if (position >= 0 && position < list->logical_size) {
        for (int i = list->logical_size - 1; i >= position; --i) {
            list->data[i + 1] = list->data[i];
        }
        list->data[position] = value;
    } else
        return false;

    list->logical_size++;
    return true;
    //TODOX: insert at end, middle, check valid

}

int check_capacity(struct ArrayList *list, bool *still_have_space) {
    if (list == NULL || still_have_space == NULL) return NULLPointer;
    if (list->logical_size < list->capacity)
        *still_have_space = true;
    else
        *still_have_space = false;
    return 0;
}

bool al_remove(struct ArrayList *list, int position, void **value) {
    if (position >= list->logical_size || list == NULL || position < 0 || value == NULL) return false;
    *value = list->data[position];
    for (int i = position; i < list->logical_size - 1; ++i) {
        list->data[i] = list->data[i + 1];
    }
    list->data[list->logical_size - 1] = NULL;
    list->logical_size--;
    return true;
//    TODOX check valid argument
}

void al_free(struct ArrayList *list) {
    if (list == NULL)
        return;
    free(list->data);
    free(list);
}

void al_print(struct ArrayList *list) {
    if (list == NULL)
        return;
    for (int i = 0; i < list->logical_size; ++i) {
        printf("%p", list->data[i]);
    }
    printf("\n");
}

int al_search(struct ArrayList *list, void *value, char *contain) {
    for (int i = 0; i < list->logical_size; ++i) {
        if (list->data[i] == value) {
            *contain = 1;
            return Success;
        }
    }
    *contain = 0;
    return Success;

}