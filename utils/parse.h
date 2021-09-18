#ifndef NYASH_PARSE_H
#define NYASH_PARSE_H

#include "vector.h"

void parse_curr_dir(char *path);
char *expand_path(char *path);
int parse_command(vector *tokens);

#endif //NYASH_PARSE_H
