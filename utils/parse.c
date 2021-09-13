#include "parse.h"
#include "../globals.h"
#include <string.h>
#include <stdio.h>

/*
 * If shellHome is a prefix of the current path
 * return index (0-based) of the first character to be printed
 * after inserting ~
 * */
void parse_curr_dir(char *path) {
    size_t currLen = strlen(path);
    if (currLen < homeLen) return;
    int i;
    for (i = 0; i < homeLen; i++) {
        if (shellHome[i] != path[i]) return;
    }
    sprintf(path, "~/%s", path + i);
}