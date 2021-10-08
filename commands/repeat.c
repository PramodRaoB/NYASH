#include "repeat.h"
#include "../utils/parse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../globals.h"

int repeat(vector *tokens) {
    if (tokens->size < 3) {
        fprintf(stderr, RED "repeat: Error missing or extra arguments\n" RESET "Usage: repeat [N >= 0] [command]\n");
        return 1;
    }
    for (int i = 0; i < strlen(tokens->arr[1]); i++) {
        if (tokens->arr[1][i] < '0' || tokens->arr[1][i] > '9') {
            fprintf(stderr, RED "repeat: Error invalid repeat count\n" RESET);
            return 1;
        }
    }
    long long numRepeat = atoll(tokens->arr[1]);
    if (numRepeat < 0) {
        fprintf(stderr, RED "repeat: Number of repeats must be non-negative\n" RESET);
        return 1;
    }
    int statusCode = 0;
    while (numRepeat--) {
        vector *newTokens = NULL;
        init_vector(&newTokens);
        for (int i = 2; i < tokens->size; i++) newTokens->push_back(newTokens, tokens->arr[i]);
        statusCode |= parse_command(newTokens);
        newTokens->erase(newTokens);
    }
    return statusCode;
}
