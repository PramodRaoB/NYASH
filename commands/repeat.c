#include "repeat.h"
#include <stdio.h>
#include <stdlib.h>
#include "../utils/parse.h"

int repeat(list *tokens) {
    if (tokens->size < 3) {
        printf("Usage: repeat [N] [command]\n");
        return 1;
    }
    long long numRepeat = atoll(tokens->arr[1]);
    if (numRepeat < 0) {
        printf("repeat: Number of repeats must be non-negative\n");
        return 1;
    }
    tokens->size -= 2;
    tokens->capacity -= 2;
    char **oldPtr = tokens->arr;
    tokens->arr = &(tokens->arr[2]);
    int statusCode = 0;
    while (numRepeat--) {
        statusCode |= parse_command(tokens);
    }
    tokens->size += 2;
    tokens->capacity += 2;
    tokens->arr = oldPtr;
    return statusCode;
}