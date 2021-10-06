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
        perror("display_prompt");
        exit(EXIT_FAILURE);
    }
    char *userName = puid->pw_name;
    if (!userName) {
        perror("display_prompt");
        exit(EXIT_FAILURE);
    }
    char *systemName = (char *) malloc(HOST_NAME_MAX);
    gethostname(systemName, HOST_NAME_MAX);
    if (!systemName) {
        perror("display_prompt");
        exit(EXIT_FAILURE);
    }

    char *curr = (char *) malloc(strlen(currPath) + 1);
    strcpy(curr, currPath);
    if (!curr) {
        perror("display_prompt");
        free(systemName);
        exit(EXIT_FAILURE);
    }
    parse_curr_dir(curr);
    printf(BLUE "%s@%s:" CYAN "%s" RESET, userName, systemName, curr);
    if (status) printf(RED ">" RESET);
    else printf(GREEN ">" RESET);
    free(systemName);
    free(curr);
}
