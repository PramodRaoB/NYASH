#include "./pwd.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../globals.h"
#include "../utils/parse.h"

int pwd(vector *tokens) {
    if (tokens->size > 1) {
        printf("pwd: Error too many arguments\n");
        return 1;
    }
    printf("%s\n", currPath);
    return 0;
}