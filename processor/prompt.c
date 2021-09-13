#include "prompt.h"
#include <unistd.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include "../utils/parse.h"

void display_prompt(int status) {
    struct passwd *puid = getpwuid(getuid());
    if (!puid) {
        perror("getpwuid() error");
        exit(errno);
    }
    char *userName = puid->pw_name;
    if (!userName) {
        perror("getpwuid() error");
        exit(errno);
    }
    char *systemName = (char *) malloc(HOST_NAME_MAX);
    gethostname(systemName, HOST_NAME_MAX);
    if (!systemName) {
        perror("gethostname()");
        exit(errno);
    }

    char *currPath = (char *) malloc(PATH_MAX);
    getcwd(currPath, PATH_MAX);
    if (!currPath) {
        perror("getcwd()");
        exit(errno);
    }
    parse_curr_dir(currPath);
    printf("%s@%s:%s>", userName, systemName, currPath);
}
