#include "history.h"
#include <stdlib.h>
#include <pwd.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "../globals.h"
#include "../utils/vector.h"

char *homeDir = NULL;
int historyFd = 0;

int history_init(void) {
    homeDir = getenv("HOME");
    if (!homeDir) {
        homeDir = getpwuid(getuid())->pw_dir;
        if (!homeDir) {
            perror("history");
            return 1;
        }
    }
    printf("homedir: %s\n", homeDir);
    char *historyFilePath = (char *) malloc(PATH_MAX + 1);
    sprintf(historyFilePath, "%s/.nyash_history", homeDir);
    historyFd = open(historyFilePath, O_CREAT | O_RDWR, 0600);
    if (historyFd < 0) {
        perror("history");
        return 1;
    }
}

int history(vector *tokens)  {
    int printNum = 0;
    if (tokens->size == 1)
        printNum = 10;
    else if (tokens->size == 2) {
        for (int i = 0; i < strlen(tokens->arr[1]); i++) {
            if (tokens->arr[1][i] < '0' || tokens->arr[1][i] > '9') {
                printf("Usage: history [0 <= N <= 20]\n");
                return 1;
            }
        }
        printNum = atoi(tokens->arr[1]);
    }
    else {
        printf("Usage: history [0 <= N <= 20]\n");
        return 1;
    }
    if (printNum < 0 || printNum > 20) {
        printf("Argument must be in range [0, 20]");
        return 1;
    }
}
