//
// Created by bongi on 23/05/2023.
//

#ifndef ETPROJECT_IARRAT_H
#define ETPROJECT_IARRAT_H

#include "stdlib.h"
#include "assert.h"

typedef struct iarray_t {
    int size;
    int *array;
    int capacity;
} iarray_t;

iarray_t *iarray_create(int capacity);
int iarray_get(iarray_t *iarray, int index);
void iarray_push(iarray_t *iarray, int value);
int iarray_pop(iarray_t *iarray);
void iarray_free(iarray_t *iarray);

#endif //ETPROJECT_IARRAT_H
