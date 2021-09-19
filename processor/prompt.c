#include "prompt.h"
#include <unistd.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <string.h>
#include "../globals.h"
#include "../utils/parse.h"
#include "../utils/colours.h"

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

    char *curr = (char *) malloc(strlen(currPath) + 1);
    strcpy(curr, currPath);
    if (!curr) {
        perror("strcpy()");
        exit(errno);
    }
    parse_curr_dir(curr);
    printf(BLUE "%s@%s:%s" RESET, userName, systemName, curr);
    if (status) printf(RED ">" RESET);
    else printf(GREEN ">" RESET);
}
