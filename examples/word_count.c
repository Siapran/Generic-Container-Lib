#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "gcl.h"

int main() {
    size_t i;
    map_iterator(str, int) itr;

    vector_t(str) my_vector;
    map_t(str, int) my_map;

    char text[] = "Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    const char delimiter[] = " ";
    char *token;

    token = strtok(text, delimiter);

    vector_init(str)(&my_vector, 0);
    map_init(str, int)(&my_map, strcmp);


    while (token != NULL) {
        vector_push_back(str)(&my_vector, token);
        token = strtok(NULL, delimiter);
    }

    for (i = 0; i < my_vector.size; ++i) {
        ++map_at(str, int)(&my_map,
                           my_vector.data[i]);;
    }

    map_foreach(str, int, &itr, &my_map) {
        printf("%*s: %d\n", 16, itr->key, itr->value);
    }

    map_destroy(str, int)(&my_map);
    vector_destroy(str)(&my_vector);


    return 0;
}