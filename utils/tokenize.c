#include "tokenize.h"
#include <string.h>
#include "../commands/history.h"

vector *tokenize_command(char *inputBuffer) {
    vector *tokens = NULL;
    init_vector(&tokens);
    char *savePtr;

    char *nextToken = strtok_r(inputBuffer, " \t\n", &savePtr);
    while (nextToken) {
        tokens->push_back(tokens, nextToken);
        nextToken = strtok_r(NULL, " \t\n", &savePtr);
    }
    insert_into_history(tokens);
    write_into_history();
    return tokens;
}

vector *tokenize_input(char *inputBuffer) {
    vector *commands = NULL;
    init_vector(&commands);
    char *savePtr;

    char *nextCommand = strtok_r(inputBuffer, ";\n", &savePtr);
    while (nextCommand) {
        commands->push_back(commands, nextCommand);
        nextCommand = strtok_r(NULL, ";\n", &savePtr);
    }
    return commands;
}