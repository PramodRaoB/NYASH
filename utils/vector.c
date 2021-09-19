#include "vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

void init_vector(vector **newList) {
    *newList = (vector *) malloc(sizeof(vector));
    if (!(*newList)) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    (*newList)->size = 0;
    (*newList)->capacity = 1;
    (*newList)->arr = (char **)malloc(sizeof(char *));
    if ((*newList)->arr == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    (*newList)->push_back = &vector_push_back;
    (*newList)->erase = &erase_vector;
}

void vector_push_back(vector *l, char *str) {
    if (l->size == l->capacity) {
        l->capacity *= 2;
        l->arr = (char **) realloc(l->arr, l->capacity * sizeof(char *));
    }
    if (str == NULL) {
        l->arr[l->size] = NULL;
        return;
    }
    l->arr[l->size] = (char *) malloc(strlen(str) + 1);
    if (l->arr[l->size] == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    strcpy(l->arr[l->size], str);
    if (l->arr[l->size] == NULL) {
        perror("strcpy");
        exit(EXIT_FAILURE);
    }
    l->size++;
}

void erase_vector(vector *l) {
    if (!l) return;
    for (int i = 0; i < l->size; i++) if(l->arr[i]) free(l->arr[i]);
    l->size = 0;
    if (l->arr)
        free(l->arr);
    free(l);
}
