//
// Created by bongi on 23/05/2023.
//

#include "string.h"

string_t *string_create(char *string, int size) {
    string_t *new_string = (string_t *)carray_create(size);

    if (new_string == NULL) return NULL;

    for (int i = 0; i < size; ++i) {
        carray_push(new_string, string[i]);
    }

    return new_string;
}

char string_get(string_t *string, int index) {
    return carray_get(string, index);
}

void string_push(string_t *string, char value) {
    carray_push(string, value);
}

char string_pop(string_t *string) {
    return carray_pop(string);
}

void string_free(string_t *string) {
    carray_free(string);
}

int string_length(string_t *string) {
    return string->size;
}

string_t *string_sconcat(string_t *string, string_t *added) {
    string_t *new_string = string_copy(string);

    if (new_string == NULL) return NULL;

    for (int i = 0; i < added->size; ++i) {
        string_push(new_string, string_get(added, i));
    }

    return new_string;
}

string_t *string_cconcat(string_t* string, char* added, int size) {
    string_t *new_string = string_copy(string);

    if (new_string == NULL) return NULL;

    for (int i = 0; i < size; ++i) {
        string_push(new_string, added[i]);
    }

    return new_string;
}

void string_print(string_t *string) {
    for (int i = 0; i < string->size; ++i) {
        printf("%c", string_get(string, i));
    }
}

string_t *string_copy(string_t *string) {
    string_t *new_string = string_create(string->array, string->size);

    return new_string;
}

bool string_sequals(string_t *string1, string_t *string2) {
    if (string1->size != string2->size) return false;

    for (int i = 0; i < string1->size; ++i) {
        if (string_get(string1, i) != string_get(string2, i)) return false;
    }

    return true;
}

bool string_cequals(string_t *string1, char *string2, int size) {
    string_t *converted_string = string_create(string2, size);

    bool is_equals = string_sequals(string1, converted_string);
    string_free(converted_string);

    return is_equals;
}