//
// Created by bongi on 23/05/2023.
//

#ifndef ETPROJECT_STRING_H
#define ETPROJECT_STRING_H

#include "./../array/carray/carray.h"

#include "stdio.h"
#include "stdbool.h"

typedef carray_t string_t;

/**
 * Create new string using dynamic array
 * @param string original string
 * @param size size of original string
 * @return new string
 */
string_t *string_create(char *string, int size);

/**
 * Get char from string
 * @param string pointer to the string
 * @param index index of char
 * @return char at index
 */
char string_get(string_t *string, int index);

/**
 * Push char at the end of string
 * @param string pointer to the string
 * @param value char to push
 */
void string_push(string_t *string, char value);

/**
 * Pop char from the end of string
 * @param string pointer to the string
 * @return char at the end of string
 */
char string_pop(string_t *string);

/**
 * Free string
 * @param string pointer to the string
 */
void string_free(string_t *string);

/**
 * Get length of string
 * @param string pointer to the string
 * @return length of string
 */
int string_length(string_t *string);

/**
 * Concatenate two strings
 * @param string pointer to the string
 * @param added pointer to the string to add
 * @return pointer to the concatenated string
 */
string_t *string_sconcat(string_t *string, string_t* added);

/**
 * Concatenate string with char array
 * @param string pointer to the string
 * @param added char array to add
 * @param size size of char array
 * @return pointer to the concatenated string
 */
string_t *string_cconcat(string_t *string, char* added, int size);

/**
 * Print string
 * @param string pointer to the string
 */
void string_print(string_t *string);

/**
 * Copy string
 * @param string pointer to the string
 * @return pointer to the copied string
 */
string_t *string_copy(string_t *string);

/**
 * Compare two strings
 * @param string1 pointer to the first string
 * @param string2 pointer to the second string
 * @return true if strings are equal, false otherwise
 */
bool string_sequals(string_t *string1, string_t *string2);

/**
 * Compare string with char array
 * @param string pointer to the string
 * @param string2 char array
 * @param size size of char array
 * @return true if strings are equal, false otherwise
 */
bool string_cequals(string_t *string, char* string2, int size);


#endif //ETPROJECT_STRING_H
