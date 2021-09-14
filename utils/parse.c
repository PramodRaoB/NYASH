#include "parse.h"
#include "../globals.h"
#include <string.h>
#include <stdio.h>
#include "../commands/pwd.h"
#include "../commands/echo.h"
#include "../commands/cd.h"

/*
 * If HOME is a prefix of the current path
 * return index (0-based) of the first character to be printed
 * after inserting ~
 * */
void parse_curr_dir(char *path) {
    size_t currLen = strlen(path);
    if (currLen < homeLen) return;
    int i;
    for (i = 0; i < homeLen; i++) {
        if (HOME[i] != path[i]) return;
    }
    sprintf(path, "~%s", path + i);
}

/*
 * given a list of tokens for a command, parses it and
 * calls the right function
 * return 1 -> unrecognized command / syntax error
 * return 2 -> parsing error
 * return -1 -> critical error
 * */
int parse_command(list *tokens) {
    if (tokens == NULL) return -1;
    if (tokens->size == 0) return 2;
    if (tokens->arr[0] == NULL) return 2;
    if (strcmp(tokens->arr[0], "pwd") == 0)
        return pwd(tokens);
    else if (strcmp(tokens->arr[0], "echo") == 0)
        return echo(tokens);
    else if (strcmp(tokens->arr[0], "cd") == 0)
        return cd(tokens);
    else {
        printf("%s: Unrecognized command\n", tokens->arr[0]);
        return 1;
    }
}