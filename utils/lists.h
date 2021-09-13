#ifndef NYASH_LISTS_H
#define NYASH_LISTS_H

typedef struct List list;
struct List {
    char **arr;
    int size;
    int capacity;

    void (*append)(list*, char*);
    void (*erase)(list*);
};

void initList(list **newList);
void appendList(list *l, char *str);
void eraseList(list *l);

#endif //NYASH_LISTS_H
