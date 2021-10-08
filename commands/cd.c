#include "cd.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "../globals.h"
#include "../utils/parse.h"

int cd(vector *tokens) {
    if (tokens->size > 2) {
        fprintf(stderr, RED "cd: Error too many arguments\n" RESET "Usage: cd [PATH]\n");
        return 1;
    }
    char *target = NULL;
    bool prev = false;
    if (tokens->size == 1) {
        target = (char *) malloc(strlen(HOME) + 1);
        if (!target) {
            perror("cd");
            return 1;
        }
        strcpy(target, HOME);
    }
    else {
        if (tokens->arr[1] && strcmp(tokens->arr[1], "-") == 0) {
            prev = true;
            target = (char *) malloc(strlen(prevPath) + 1);
            if (!target) {
                perror("cd");
                return 1;
            }
            strcpy(target, prevPath);
        }
        else {
            target = expand_path(tokens->arr[1]);
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
            free(temp);
        }
        free(target);
        return 0;
    }
    else {
        fprintf(stderr, RED "cd: Invalid target\n" RESET);
        free(target);
        return 1;
    }
}
