#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

void initList(list **newList) {
    *newList = (list *) malloc(sizeof(list));
    if (!(*newList)) {
        perror("malloc()");
        exit(errno);
    }
    (*newList)->size = 0;
    (*newList)->capacity = 1;
    (*newList)->arr = (char **)malloc(sizeof(char *));
    (*newList)->append = &appendList;
    (*newList)->erase = &eraseList;
}

void appendList(list *l, char *str) {
    if (l->size == l->capacity) {
        l->capacity *= 2;
        l->arr = (char **) realloc(l->arr, l->capacity * sizeof(char *));
    }
    if (str == NULL) {
        l->arr[l->size] = NULL;
        return;
    }
    l->arr[l->size] = (char *) malloc(strlen(str) + 1);
    strcpy(l->arr[l->size], str);
    l->size++;
}

void eraseList(list *l) {
    if (!l) return;
    for (int i = 0; i < l->size; i++) if(l->arr[i]) free(l->arr[i]);
    l->size = 0;
    if (l->arr)
        free(l->arr);
    free(l);
}
