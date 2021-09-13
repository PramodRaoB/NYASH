#include "pwd.h"
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

char *pwd(void) {
    char *currPath = (char *) malloc(PATH_MAX);
    getcwd(currPath, PATH_MAX);
    return currPath;
}