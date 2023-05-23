//
// Created by bongi on 23/05/2023.
//

#include "farray.h"


/**
 * Create a new dynamic array
 * @param capacity initial capacity of the dynamic array
 * @return pointer to the dynamic array, NULL if memory allocation failed
 */
farray_t *farray_create(int capacity) {
    farray_t *farray = malloc(sizeof(farray_t));

    if (farray == NULL) {
        return NULL;
    }

    farray->size = 0;
    farray->capacity = capacity;
    farray->array = malloc(sizeof(float) * capacity);

    if (farray->array == NULL) {
        free(farray);
        return NULL;
    }

    return farray;
}

/**
 * Retrieve a value from the dynamic array
 * @param farray pointer to the dynamic array
 * @param index index of the value to retrieve, must be less than the size of the dynamic array
 * @return value at the given index
 */
float farray_get(farray_t *farray, int index) {
    assert(index < farray->size);

    return farray->array[index];
}

/**
 * Add a value to the end of the dynamic array
 * @param farray pointer to the dynamic array
 * @param value value to add to the dynamic array
 */
void farray_push(farray_t *farray, float value) {
    if (farray->size == farray->capacity) {
        farray->capacity *= 2;
        farray->array = realloc(farray->array, sizeof(float) * farray->capacity);
    }

    farray->array[farray->size] = value;
    farray->size++;
}

/**
 * Remove a value from the end of the dynamic array
 * @param farray pointer to the dynamic array, must not be empty
 * @return value removed from the dynamic array
 */
float farray_pop(farray_t *farray) {
    assert(farray->size > 0);

    farray->size--;

    return farray->array[farray->size];
}

/**
 * Free the memory allocated for the dynamic array
 * @param farray pointer to the dynamic array
 */
void farray_free(farray_t *farray) {
    free(farray->array);
    free(farray);
}