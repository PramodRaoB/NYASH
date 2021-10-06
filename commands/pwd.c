#include "./pwd.h"
#include <stdio.h>
#include "../globals.h"

int pwd(vector *tokens) {
    if (tokens->size > 1) {
        printf(RED "pwd: Error too many arguments\n" RESET);
        return 1;
    }
    printf("%s\n", currPath);
    return 0;
}