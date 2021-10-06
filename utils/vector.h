#ifndef NYASH_VECTOR_H
#define NYASH_VECTOR_H

typedef struct Vector vector;
struct Vector {
    char **arr;
    int size;
    int capacity;

    void (*push_back)(vector*, char*);
    void (*erase)(vector*);
    void (*clear)(vector*);
};

void init_vector(vector **newList);
void vector_push_back(vector *l, char *str);
void erase_vector(vector *l);
void clear_vector(vector *l);

#endif //NYASH_VECTOR_H
