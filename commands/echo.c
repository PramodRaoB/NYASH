#include "echo.h"
#include <stdio.h>

int echo(list *tokens) {
    for (int i = 1; i < tokens->size - 1; i++)
        printf("%s ", tokens->arr[i]);
    if (tokens->size >= 2) printf("%s", tokens->arr[tokens->size - 1]);
    printf("\n");
    return 0;
}