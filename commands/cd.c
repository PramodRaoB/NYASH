#include "cd.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "../globals.h"
#include "../utils/parse.h"

int cd(list *tokens) {
    if (tokens->size > 2) {
        printf("cd: Error too many arguments\n");
        return 1;
    }
    char *target = NULL;
    bool prev = false;
    if (tokens->size == 1)
        target = HOME;
    else {
        target = tokens->arr[1];
        if (target && strcmp(target, "-") == 0) {
            prev = true;
            target = prevPath;
        }
        if (target) {
            if (strlen(target) == 1 && target[0] == '~')
                target = HOME;
            else if (strlen(target) == 2 && target[0] == '~' && target[1] == '/')
                target = HOME;
            else if (strlen(target) > 2 && target[0] == '~' && target[1] == '/') {
                if (chdir(HOME) != -1) target = target + 2;
            }
        }
    }
    if (target != NULL && chdir(target) != -1) {
        free(prevPath);
        prevPath = currPath;
        currPath = (char *) calloc(PATH_MAX, sizeof(char));
        getcwd(currPath, PATH_MAX);
        if (prev) {
            char *temp = (char *) malloc(strlen(currPath) + 1);
            strcpy(temp, currPath);
            parse_curr_dir(temp);
            printf("%s\n", temp);
        }
        return 0;
    }
    else {
        printf("cd: Invalid target\n");
        return 1;
    }
}
