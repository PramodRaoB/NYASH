#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include "pinfo.h"
#include "../utils/tokenize.h"
#include "../utils/parse.h"

int pinfo(vector *tokens) {
    if (tokens->size > 2) {
        printf("pinfo: Error too many arguments\n");
        return 1;
    }
    pid_t pid;
    if (tokens->size == 1) pid = getpid();
    else pid = atoi(tokens->arr[1]);

    //PID_MAX_LIMIT is 2^22 ~ 4 million => 6 byte string
    char *procStat = (char *) malloc(20);
    if (!procStat) {
        perror("pinfo");
        return 1;
    }
    sprintf(procStat, "/proc/%d/stat", pid);
    FILE *status = fopen(procStat, "r");
    if (status == NULL) {
        printf("pinfo: Error process not found\n");
        free(procStat);
        return 1;
    }

    char *data = NULL;
    size_t dataSize = 0;
    if (getline(&data, &dataSize, status) == -1) {
        perror("pinfo");
        free(data);
        free(procStat);
        return 1;
    }
    fclose(status);

    vector *statArgs = tokenize_command(data);
    if (statArgs == NULL) {
        free(data);
        free(procStat);
        return 1;
    }
    //man 5 proc
    printf("pid -- %s\n", statArgs->arr[0]);
    printf("Process Status -- %s", statArgs->arr[2]);
    //apend + if foreground process
    printf(strcmp(statArgs->arr[4], statArgs->arr[7]) == 0 ? "+\n" : "\n");
    printf("memory -- %s bytes\n", statArgs->arr[22]);

    char *procExe = (char *) malloc(20);
    if (!procExe) {
        perror("pinfo");
        statArgs->erase(statArgs);
        free(data);
        free(procStat);
        return 1;
    }
    sprintf(procExe, "/proc/%d/exe", pid);
    char *exePath = (char *) malloc(PATH_MAX + 1);
    if (!exePath) {
        perror("pinfo");
        free(procExe);
        statArgs->erase(statArgs);
        free(data);
        free(procStat);
        return 1;
    }
    size_t exeSize = PATH_MAX + 1;
    ssize_t bytesRead = readlink(procExe, exePath, exeSize);
    if (bytesRead == -1) {
        perror("readlink");
        free(exePath);
        free(procExe);
        statArgs->erase(statArgs);
        free(data);
        free(procStat);
        return 1;
    }
    exePath[bytesRead] = '\0';
    parse_curr_dir(exePath);
    printf("Executable Path -- %s\n", exePath);
    free(exePath);
    free(procExe);

    statArgs->erase(statArgs);
    free(data);
    free(procStat);
    return 0;
}
