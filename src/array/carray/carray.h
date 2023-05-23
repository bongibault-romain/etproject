//
// Created by bongi on 23/05/2023.
//

#ifndef ETPROJECT_IARRAT_H
#define ETPROJECT_IARRAT_H

#include "stdlib.h"
#include "assert.h"

typedef struct carray_t {
    int size;
    char *array;
    int capacity;
} carray_t;

carray_t *carray_create(int capacity);
char carray_get(carray_t *carray, int index);
void carray_push(carray_t *carray, char value);
char carray_pop(carray_t *carray);
void carray_free(carray_t *carray);

#endif //ETPROJECT_IARRAT_H
