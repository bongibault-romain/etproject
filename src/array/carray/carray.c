//
// Created by bongi on 23/05/2023.
//

#include "carray.h"

/**
 * Create a new dynamic array
 * @param capacity initial capacity of the dynamic array
 * @return pointer to the dynamic array, NULL if memory allocation failed
 */
carray_t *carray_create(int capacity) {
    carray_t *carray = malloc(sizeof(carray_t));

    if (carray == NULL) {
        return NULL;
    }

    carray->size = 0;
    carray->capacity = capacity;
    carray->array = malloc(sizeof(char) * capacity);

    if (carray->array == NULL) {
        free(carray);
        return NULL;
    }

    return carray;
}

/**
 * Retrieve a value from the dynamic array
 * @param carray pointer to the dynamic array
 * @param index index of the value to retrieve, must be less than the size of the dynamic array
 * @return value at the given index
 */
char carray_get(carray_t *carray, int index) {
    assert(index < carray->size);

    return carray->array[index];
}

/**
 * Add a value to the end of the dynamic array
 * @param carray pointer to the dynamic array
 * @param value value to add to the dynamic array
 */
void carray_push(carray_t *carray, char value) {
    if (carray->size == carray->capacity) {
        carray->capacity *= 2;
        carray->array = realloc(carray->array, sizeof(char) * carray->capacity);
    }

    carray->array[carray->size] = value;
    carray->size++;
}

/**
 * Remove a value from the end of the dynamic array
 * @param carray pointer to the dynamic array, must not be empty
 * @return value removed from the dynamic array
 */
char carray_pop(carray_t *carray) {
    assert(carray->size > 0);

    carray->size--;

    return carray->array[carray->size];
}

/**
 * Free the memory allocated for the dynamic array
 * @param carray pointer to the dynamic array
 */
void carray_free(carray_t *carray) {
    free(carray->array);
    free(carray);
}