#ifndef GLOBALS_H
#define GLOBALS_H
#include <stddef.h>
#include "utils/list.h"

extern char *HOME;
extern char *currPath;
extern char *prevPath;
extern size_t homeLen;

extern char *historyFilePath;
extern header *historyList;

#endif