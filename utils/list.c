#include "list.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

int init_list(header **h) {
    *h = (header *) malloc(sizeof(header));
    if (!(*h)) {
        perror("init_vector");
        return 1;
    }
    (*h)->size = 0;
    (*h)->start = NULL;
    (*h)->insert = insert_list;
    (*h)->erase = erase_list;
    (*h)->trim = delete_last;
    return 0;
}

list *create_node(char *str) {
    list *newNode = (list *) malloc(sizeof(list));
    if (!newNode) {
        perror("create_node");
        return NULL;
    }
    newNode->next = NULL;
    if (str == NULL) {
        newNode->str = NULL;
        return newNode;
    }
    newNode->str = (char *) malloc(strlen(str) + 1);
    if (!(newNode->str)) {
        perror("create_node");
        return NULL;
    }
    strcpy(newNode->str, str);
    if (!(newNode->str)) {
        perror("create_node");
        return NULL;
    }
    return newNode;
}

int insert_list(header *h, char *str) {
    list *node = create_node(str);
    if (!node) return 1;
    h->size++;
    list *curr = h->start;
    node->next = NULL;
    if (!curr) {
        h->start = node;
        return 0;
    }
    while (curr->next) curr = curr->next;
    curr->next = node;
    return 0;
}

void delete_last(header *h) {
    if (!h) return;
    if (h->size == 0) return;
    if (h->size == 1) {
        free(h->start->str);
        free(h->start);
        h->start = NULL;
        return;
    }
    list *temp = h->start->next;
    free(h->start->str);
    free(h->start);
    h->start = temp;
}

void erase_list(header *h) {
    if (!h) return;
    list *temp = h->start;
    while (temp != NULL) {
        list *next = temp->next;
        free (temp);
        temp = next;
    }
    free(h);
}
