//
// Created by bongi on 23/05/2023.
//

#ifndef ETPROJECT_IARRAT_H
#define ETPROJECT_IARRAT_H

#include "stdlib.h"
#include "assert.h"

typedef struct farray_t {
    int size;
    float *array;
    int capacity;
} farray_t;

farray_t *farray_create(int capacity);
float farray_get(farray_t *iarray, int index);
void farray_push(farray_t *iarray, float value);
float farray_pop(farray_t *iarray);
void farray_free(farray_t *iarray);

#endif //ETPROJECT_IARRAT_H
