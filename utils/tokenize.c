#include "tokenize.h"
#include <string.h>
#include <stdio.h>

list *tokenize_command(char *inputBuffer) {
    list *tokens = NULL;
    initList(&tokens);
    char *savePtr;

    char *nextToken = strtok_r(inputBuffer, " \t\n", &savePtr);
    while (nextToken) {
        tokens->append(tokens, nextToken);
        nextToken = strtok_r(NULL, " \t\n", &savePtr);
    }
    return tokens;
}
