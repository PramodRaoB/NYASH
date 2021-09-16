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

list *tokenize_input(char *inputBuffer) {
    list *commands = NULL;
    initList(&commands);
    char *savePtr;

    char *nextCommand = strtok_r(inputBuffer, ";\n", &savePtr);
    while (nextCommand) {
        commands->append(commands, nextCommand);
        nextCommand = strtok_r(NULL, ";\n", &savePtr);
    }
    return commands;
}