#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char *str = NULL;
  size_t len;
  list *l;
  initList(&l);
  getline(&str, &len, stdin);
  l->append(l, str);
  getline(&str, &len, stdin);
  l->append(l, str);

  getline(&str, &len, stdin);
  l->append(l, str);

  getline(&str, &len, stdin);
  l->append(l, str);
  getline(&str, &len, stdin);
  l->append(l, str);
  getline(&str, &len, stdin);
  l->append(l, str);
  for (int i = 0; i < l->size; i++) {
    printf("%s\n", l->arr[i]);
  }
  l->erase(l);
  free(str);
  return 0;
}
