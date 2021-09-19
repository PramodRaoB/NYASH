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
    HOME = (char *)malloc(PATH_MAX + 1);
    if (!HOME) {
        perror("initialize_shell");
        exit(EXIT_FAILURE);
    }
    currPath = (char *)malloc(PATH_MAX + 1);
    if (!currPath) {
        perror("initialize_shell");
        exit(EXIT_FAILURE);
    }
    prevPath = (char *)malloc(PATH_MAX + 1);
    if (!prevPath) {
        perror("initialize_shell");
        exit(EXIT_FAILURE);
    }
    if (getcwd(HOME, PATH_MAX) == NULL) {
        perror("initialize_shell");
        exit(EXIT_FAILURE);
    }
    strcpy(currPath, HOME);
    strcpy(prevPath, HOME);
    homeLen = strlen(HOME);

    if (history_init()) {
        exit(EXIT_FAILURE);
    }
    init_jobs(&jobs);
}