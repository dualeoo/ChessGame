#ifndef ARRAY_LIST
#define ARRAY_LIST

#include <stdbool.h>

struct ArrayList {
    unsigned int logical_size;
    unsigned int capacity;
    void **data;

    bool (*al_insert)(struct ArrayList *list, int position, void *value);

    bool (*al_remove)(struct ArrayList *list, int position, void **value);

    int (*al_search)(struct ArrayList *list, void *value, char *contain);

};

/**
 * Create an array list by allocating a struct array_list and init its contents to an empty list.
 * @return a pointer to a newly allocated struct array_list, or NULL if it cannot be allocated
 */
struct ArrayList *ArrayListInit();

/**
 * Insert a value at a given position in the array list.
 * @param list insert a value in this list
 * @param position insert a value at this position (it can insert at the end, 1 position after
 *          the last element, and it can insert before the end by moving elements to the right
 *          to make space)
 * @param value the value to insert
 * @return true on successful insert, or false if the value cannot be inserted at this position
 */
bool al_insert(struct ArrayList *list, int position, void *value);

/**
 * Remove a value at a given position from the array list.
 * @param list remove a value from this list
 * @param position remove a value from this position (it cannot leave any position empty, so
 *          it might need to move elements to the left to avoid leaving an empty position)
 * @param value the value removed from the list is saved here
 * @return true on successful remove, or false if the value cannot be removed from this position
 */
bool al_remove(struct ArrayList *list, int position, void **value);

/**
 * Free all the memory used by an array list.
 * @param list the list to free
 */
void al_free(struct ArrayList *list);

/**
 * Print the contents of an array list.
 * @param list the list to be printed
 */
void al_print(struct ArrayList *list);

/*
 * Check if the logical size of the array has reached the capacity
 * @param list the list to check
 * @param still_have_space checking result
 * @return the error code*/
int check_capacity(struct ArrayList *list, bool *still_have_space);

int al_search(struct ArrayList *list, void *value, char *contain);

#endif
