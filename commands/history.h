#ifndef NYASH_HISTORY_H
#define NYASH_HISTORY_H

#include "../utils/vector.h"

int history_init(void);
int history(vector *tokens);
int insert_into_history(vector *tokens);
int write_into_history(void);

#endif //NYASH_HISTORY_H
