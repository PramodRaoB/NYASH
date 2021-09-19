#include "parse.h"
#include "../globals.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../commands/pwd.h"
#include "../commands/echo.h"
#include "../commands/cd.h"
#include "../commands/ls.h"
#include "../commands/pinfo.h"
#include "../processor/sysCommands.h"
#include "../commands/repeat.h"
#include "../commands/history.h"

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

char *expand_path(char *path) {
    char *finalPath;
    if (path == NULL) return NULL;
    if (strlen(path) == 1 && path[0] == '~') {
        finalPath = (char *) malloc(strlen(HOME) + 1);
        strcpy(finalPath, HOME);
        return finalPath;
    }
    if (strlen(path) == 2 && path[0] == '~' && path[1] == '/') {
        finalPath = (char *) malloc(strlen(HOME) + 1);
        strcpy(finalPath, HOME);
        return finalPath;
    }
    if (strlen(path) > 2 && path[0] == '~' && path[1] == '/') {
        finalPath = (char *) malloc(strlen(HOME) + strlen(path));
        strcpy(finalPath, HOME);
        strcat(finalPath, path + 1);
        return finalPath;
    }
    finalPath = (char *) malloc(strlen(path) + 1);
    strcpy(finalPath, path);
    return finalPath;
}

int parse_command(vector *tokens) {
    if (tokens == NULL) return 1;
    if (tokens->size == 0) return 1;
    if (tokens->arr[0] == NULL) return 1;
    if (strcmp(tokens->arr[0], "pwd") == 0)
        return pwd(tokens);
    else if (strcmp(tokens->arr[0], "echo") == 0)
        return echo(tokens);
    else if (strcmp(tokens->arr[0], "cd") == 0)
        return cd(tokens);
    else if (strcmp(tokens->arr[0], "ls") == 0)
        return ls(tokens);
    else if (strcmp(tokens->arr[0], "pinfo") == 0)
        return pinfo(tokens);
    else if (strcmp(tokens->arr[0], "repeat") == 0)
        return repeat(tokens);
    else if (strcmp(tokens->arr[0], "history") == 0)
        return history(tokens);
    else if (strcmp(tokens->arr[0], "exit") == 0) {
        return -1;
    }
    else {
        return exec_sys_command(tokens);
    }
}