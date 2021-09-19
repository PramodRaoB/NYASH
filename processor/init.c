#include <limits.h>
#include <unistd.h>
#include <stdio.h>
#include "init.h"
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "../commands/history.h"

char *HOME = NULL;
char *currPath = NULL;
char *prevPath = NULL;
size_t homeLen = 0;
jobList *jobs = NULL;

void initialize_shell(void) {
    HOME = (char *)malloc(PATH_MAX);
    currPath = (char *)malloc(PATH_MAX);
    prevPath = (char *)malloc(PATH_MAX);
    if (HOME == NULL) {
        perror("malloc()");
        exit(errno);
    }
    if (getcwd(HOME, PATH_MAX) == NULL) {
        perror("getcwd() error");
        exit(errno);
    }
    strcpy(currPath, HOME);
    strcpy(prevPath, HOME);
    homeLen = strlen(HOME);

    history_init();
    init_jobs(&jobs);
}