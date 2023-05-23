//
// Created by bongi on 23/05/2023.
//

#include "iarray.h"


/**
 * Create a new dynamic array
 * @param capacity initial capacity of the dynamic array
 * @return pointer to the dynamic array, NULL if memory allocation failed
 */
iarray_t *iarray_create(int capacity) {
    iarray_t *iarray = malloc(sizeof(iarray_t));

    if (iarray == NULL) {
        return NULL;
    }

    iarray->size = 0;
    iarray->capacity = capacity;
    iarray->array = malloc(sizeof(int) * capacity);

    if (iarray->array == NULL) {
        free(iarray);
        return NULL;
    }

    return iarray;
}

/**
 * Retrieve a value from the dynamic array
 * @param iarray pointer to the dynamic array
 * @param index index of the value to retrieve, must be less than the size of the dynamic array
 * @return value at the given index
 */
int iarray_get(iarray_t *iarray, int index) {
    assert(index < iarray->size);

    return iarray->array[index];
}

/**
 * Add a value to the end of the dynamic array
 * @param iarray pointer to the dynamic array
 * @param value value to add to the dynamic array
 */
void iarray_push(iarray_t *iarray, int value) {
    if (iarray->size == iarray->capacity) {
        iarray->capacity *= 2;
        iarray->array = realloc(iarray->array, sizeof(int) * iarray->capacity);
    }

    iarray->array[iarray->size] = value;
    iarray->size++;
}

/**
 * Remove a value from the end of the dynamic array
 * @param iarray pointer to the dynamic array, must not be empty
 * @return value removed from the dynamic array
 */
int iarray_pop(iarray_t *iarray) {
    assert(iarray->size > 0);

    iarray->size--;

    return iarray->array[iarray->size];
}

/**
 * Free the memory allocated for the dynamic array
 * @param iarray pointer to the dynamic array
 */
void iarray_free(iarray_t *iarray) {
    free(iarray->array);
    free(iarray);
}