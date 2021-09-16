#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include "pinfo.h"
#include "../utils/tokenize.h"

int pinfo(list *tokens) {
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
        perror("malloc()");
        return 1;
    }
    sprintf(procStat, "/proc/%d/stat", pid);
    FILE *status = fopen(procStat, "r");
    if (status == NULL) {
        printf("pinfo: Error process not found\n");
        return 1;
    }

    char *data = NULL;
    size_t dataSize = 0;
    if (getline(&data, &dataSize, status) == -1) {
        perror("getline()");
        return 1;
    }
    fclose(status);

    list *statArgs = tokenize_command(data);
    if (statArgs == NULL) return 1;
    //man 5 proc
    printf("pid -- %d\n", atoi(statArgs->arr[0]));
    printf("Process Status -- %s\n", statArgs->arr[2]);
    printf("memory -- %lu\n", atol(statArgs->arr[22]));

    char *procExe = (char *) malloc(20);
    if (!procExe) {
        perror("malloc()");
        return 1;
    }
    sprintf(procExe, "/proc/%d/exe", pid);
    char *exePath = (char *) malloc(PATH_MAX);
    if (!exePath) {
        perror("malloc()");
        return 1;
    }
    size_t exeSize = PATH_MAX;
    ssize_t bytesRead = readlink(procExe, exePath, exeSize);
    if (bytesRead == -1) {
        perror("readlink()");
        return 1;
    }
    printf("Executable Path -- ");
    for (int i = 0; i < bytesRead; i++) printf("%c", exePath[i]);
    printf("\n");
    free(exePath);

    statArgs->erase(statArgs);
    free(data);
    free(procStat);
    return 0;
}
