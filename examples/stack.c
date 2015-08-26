#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "gcl.h"

int main() {
    size_t i;

    list_t(int) *stack = list_new(int)();

    for (i = 0; i < 10; ++i)
        list_push_back(int)(stack, i);

    while (stack->size != 0)
        printf("%d ", list_pop_back(int)(stack));

    for (i = 0; i < 10; ++i)
        list_push_front(int)(stack, i);

    while (stack->size >= 2) {
        printf("%d ", list_pop_back(int)(stack));
        printf("%d ", list_pop_front(int)(stack));
    }

    list_delete(int)(stack);

    return 0;
}