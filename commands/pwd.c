#include "./pwd.h"
#include <stdio.h>
#include "../globals.h"

int pwd(vector *tokens) {
    if (tokens->size > 1) {
        fprintf(stderr, RED "pwd: Error too many arguments\n" RESET "Usage: pwd\n");
        return 1;
    }
    printf("%s\n", currPath);
    return 0;
}