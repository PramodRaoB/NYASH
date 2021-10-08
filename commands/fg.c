#include "fg.h"
#include <stdio.h>
#include "../globals.h"
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

int fg(vector *tokens) {
    if (tokens->size != 2) {
        fprintf(stderr, RED "fg: Error missing or extra arguments\n" RESET "Usage: fg [JOB-NUMBER]\n");
        return 1;
    }
    long jobNumber = 0;
    for (int i = 0; i < strlen(tokens->arr[1]); i++) {
        if (tokens->arr[1][i] < '0' || tokens->arr[1][i] > '9') {
            fprintf(stderr, RED "fg: Invalid job number entered\n" RESET);
            return 1;
        }
    }
    errno = 0;
    char *endPtr = NULL;
    jobNumber = strtol(tokens->arr[1], &endPtr, 10);
    if (errno != 0 || endPtr == tokens->arr[1]) {
        fprintf(stderr, RED "fg: Invalid job number entered\n" RESET);
        return 1;
    }
    int pid = jobs->find_by_number(jobs, jobNumber);
    if (pid < 0) {
        fprintf(stderr, RED "fg: No job exists with given number\n" RESET "Use jobs to obtain valid job numbers\n");
        return 1;
    }
    if (kill(pid, SIGCONT) < 0) {
        perror(RED "fg" RESET);
        return 1;
    }

    int statusCode = 0;

    signal(SIGTTOU, SIG_IGN);
    signal(SIGTTIN, SIG_IGN);
    tcsetpgrp(STDIN_FILENO, pid);

    waitpid(pid, &statusCode, WUNTRACED);

    tcsetpgrp(STDIN_FILENO, getpgrp());

    int currStatus = 0;
    if (!WIFSTOPPED(statusCode)) jobs->delete(jobs, pid);
    else {
        if (WSTOPSIG(statusCode) == SIGTSTP) {
            job *curr = jobs->proc(jobs, pid);
            printf("[%d] suspended %s [%d]\n", curr->jobNumber, curr->name, curr->pid);
        }
        currStatus = 1;
    }
    if (!WIFEXITED(statusCode)) currStatus = 1;
    signal(SIGTTOU, SIG_DFL);
    signal(SIGTTIN, SIG_DFL);
    return currStatus;
}
