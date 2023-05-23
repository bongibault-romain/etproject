#include <stdio.h>

#include "string/string.h"

int main() {
    string_t *str = string_create("Hello, World!", 13);
    string_t *str2 = string_create("Bonsoir les gens!", 17);

    string_t *result = string_cconcat(str, "Bonjour", 7);

    string_print(str);
    printf("\n");
    string_print(result);

    string_free(str);
    string_free(str2);
    string_free(result);

    return 0;
}
