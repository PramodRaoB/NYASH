#include "sig.h"
#include <stdio.h>
#include "../globals.h"
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>

int sig(vector *tokens) {
    if (tokens->size != 3) {
        fprintf(stderr, RED "sig: Error missing or extra arguments\n" RESET "Usage: sig [JOB-NUMBER] [SIGNAL-NUMBER]\n");
        return 1;
    }
    long jobNumber = 0;
    for (int i = 0; i < strlen(tokens->arr[1]); i++) {
        if (tokens->arr[1][i] < '0' || tokens->arr[1][i] > '9') {
            fprintf(stderr, RED "sig: Invalid job number\n" RESET);
            return 1;
        }
    }
    errno = 0;
    char *endPtr = NULL;
    jobNumber = strtol(tokens->arr[1], &endPtr, 10);
    if (errno != 0 || endPtr == tokens->arr[1]) {
        fprintf(stderr, RED "sig: Invalid job number\n" RESET);
        return 1;
    }
    int pid = jobs->find_by_number(jobs, jobNumber);
    if (pid < 0) {
        fprintf(stderr, RED "sig: No job exists with given number\n" RESET "Use jobs to obtain valid job numbers\n");
        return 1;
    }
    long sigNumber = 0;
    for (int i = 0; i < strlen(tokens->arr[2]); i++) {
        if (tokens->arr[1][i] < '0' || tokens->arr[2][i] > '9') {
            fprintf(stderr, RED "sig: Invalid signal number\n" RESET);
            return 1;
        }
    }
    errno = 0;
    endPtr = NULL;
    sigNumber = strtol(tokens->arr[2], &endPtr, 10);
    if (errno != 0 || endPtr == tokens->arr[2]) {
        fprintf(stderr, RED "sig: Invalid signal number\n" RESET);
        return 1;
    }
    if (kill(pid, sigNumber) < 0) {
        perror(RED "sig" RESET);
        return 1;
    }
    return 0;
}
