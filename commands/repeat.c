#include "repeat.h"
#include "../utils/parse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int repeat(list *tokens) {
    if (tokens->size < 3) {
        printf("Usage: repeat [N] [command]\n");
        return 1;
    }
    for (int i = 0; i < strlen(tokens->arr[1]); i++) {
        if (tokens->arr[1][i] < '0' || tokens->arr[1][i] > '9') {
            printf("Usage: repeat [N] [command]\n");
            return 1;
        }
    }
    long long numRepeat = atoll(tokens->arr[1]);
    if (numRepeat < 0) {
        printf("repeat: Number of repeats must be non-negative\n");
        return 1;
    }
    int statusCode = 0;
    while (numRepeat--) {
        list *newTokens = NULL;
        initList(&newTokens);
        for (int i = 2; i < tokens->size; i++) newTokens->append(newTokens, tokens->arr[i]);
        statusCode |= parse_command(newTokens);
        newTokens->erase(newTokens);
    }
    return statusCode;
}
