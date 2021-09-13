#include <malloc.h>
#include <limits.h>
#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include "init.h"

void initialize_shell(void) {
    shellHome = (char *)malloc(PATH_MAX);
    assert(shellHome != NULL);
    if (getcwd(shellHome, PATH_MAX) == NULL) {
        perror("getcwd() error");
    }
}