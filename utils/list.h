#ifndef NYASH_LIST_H
#define NYASH_LIST_H

typedef struct List list;
typedef struct Header header;

struct Header {
    int size;
    list *start;
    int (*insert)(header *, char *);
    void (*erase)(header *);
    void (*trim)(header *);
};
struct List {
    list *next;
    char *str;
};

int init_list(header **h);
list *create_node(char *str);
int insert_list(header *h, char *str);
void erase_list(header *h);
void delete_last(header *h);

#endif //NYASH_LIST_H
