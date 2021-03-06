#ifndef GLOBALS_H
#define GLOBALS_H
#include <stddef.h>
#include "utils/list.h"
#include "utils/job_list.h"
#include "./utils/colours.h"

extern char *HOME;
extern char *currPath;
extern char *prevPath;
extern size_t homeLen;

extern char *historyFilePath;
extern header *historyList;

extern jobList *jobs;
extern int currJob;

#endif