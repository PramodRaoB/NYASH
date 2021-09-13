#include <limits.h>
#include <unistd.h>
#include <stdio.h>
#include "init.h"
#include <stdlib.h>
#include <errno.h>
#include <string.h>

char *shellHome = NULL;
char *currPath = NULL;
char *prevPath = NULL;
size_t homeLen = 0;

void initialize_shell(void) {
    shellHome = (char *)malloc(PATH_MAX);
    currPath = (char *)malloc(PATH_MAX);
    prevPath = (char *)malloc(PATH_MAX);
    if (shellHome == NULL) {
        perror("malloc()");
        exit(errno);
    }
    if (getcwd(shellHome, PATH_MAX) == NULL) {
        perror("getcwd() error");
        exit(errno);
    }
    strcpy(currPath, shellHome);
    strcpy(prevPath, shellHome);
    homeLen = strlen(shellHome);
}