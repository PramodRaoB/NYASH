#include "cd.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "../globals.h"

int cd(list *tokens) {
    if (tokens->size > 2) {
        printf("cd: Error too many arguments\n");
        return 1;
    }
    char *target = NULL;
    if (tokens->size == 1)
        target = HOME;
    else {
        target = tokens->arr[1];
        if (target && strcmp(target, "~") == 0) target = HOME;
        if (target && strcmp(target, "-") == 0) target = prevPath;
    }
    if (target != NULL && chdir(target) != -1) {
        free(prevPath);
        prevPath = currPath;
        currPath = (char *) calloc(PATH_MAX, sizeof(char));
        getcwd(currPath, PATH_MAX);
        return 0;
    }
    else {
        printf("cd: Invalid target\n");
        return 1;
    }
}
