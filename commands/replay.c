#include "replay.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include "../utils/parse.h"

int __is_command(char *str) {
    if (!strcmp(str, "-command") || !strcmp(str, "-c") || !strcmp(str, "--command"))
        return 1;
    return 0;
}
int __is_interval(char *str) {
    if (!strcmp(str, "-interval") || !strcmp(str, "-i") || !strcmp(str, "--interval"))
        return 1;
    return 0;
}
int __is_period(char *str) {
    if (!strcmp(str, "-period") || !strcmp(str, "-p") || !strcmp(str, "--period"))
        return 1;
    return 0;
}

int replay(vector *tokens) {
    vector *command = NULL;
    long interval = 0, period = 0;
    int hasCommand = 0, hasInterval = 0, hasPeriod = 0;
    for (int i = 1; i < tokens->size; i++) {
        if (__is_command(tokens->arr[i])) {
            if (hasCommand) {
                fprintf(stderr, RED "replay: Error multiple command arguments found\n" RESET "Usage: replay --command [STR] --interval [N] --period [N]\n");
                return 1;
            }
            if (i == tokens->size - 1) {
                fprintf(stderr, RED "replay: Error missing command argument\n" RESET "Usage: replay --command [STR] --interval [N] --period [N]\n");
                return 1;
            }
            hasCommand = 1;
            init_vector(&command);
            int j;
            for (j = i + 1; j < tokens->size; j++) {
                if (__is_command(tokens->arr[j])) {
                    fprintf(stderr, RED "replay: Error multiple command arguments found\n" RESET "Usage: replay --command [STR] --interval [N] --period [N]\n");
                    return 1;
                }
                if (__is_interval(tokens->arr[j]) || __is_period(tokens->arr[j])) {
                    if (j == i + 1) {
                        fprintf(stderr, RED "replay: Error missing command argument\n" RESET "Usage: replay --command [STR] --interval [N] --period [N]\n");
                        return 1;
                    }
                    break;
                }
                command->push_back(command, tokens->arr[j]);
            }
            i = j;
        }
        else if (__is_interval(tokens->arr[i])) {
            if (hasInterval) {
                fprintf(stderr, RED "replay: Error multiple interval arguments found\n" RESET "Usage: replay --command [STR] --interval [N] --period [N]\n");
                return 1;
            }
            if (i == tokens->size - 1) {
                fprintf(stderr, RED "replay: Error missing interval argument\n" RESET "Usage: replay --command [STR] --interval [N] --period [N]\n");
                return 1;
            }
            hasInterval = 1;
            for (int j = 0; j < strlen(tokens->arr[i + 1]); j++) {
                if (tokens->arr[i + 1][j] < '0' || tokens->arr[i + 1][j] > '9') {
                    fprintf(stderr, RED "replay: Error invalid interval argument\n" RESET "Usage: replay --command [STR] --interval [N] --period [N]\n");
                    return 1;
                }
            }
            char *endPtr = NULL;
            errno = 0;
            interval = strtol(tokens->arr[i + 1], &endPtr, 10);
            if (errno != 0 || endPtr == tokens->arr[i + 1]) {
                fprintf(stderr, RED "replay: Error invalid interval argument\n" RESET "Usage: replay --command [STR] --interval [N] --period [N]\n");
                return 1;
            }
            i++;
        }
        else if (__is_period(tokens->arr[i])) {
            if (hasPeriod) {
                fprintf(stderr, RED "replay: Error multiple period arguments found\n" RESET "Usage: replay --command [STR] --interval [N] --period [N]\n");
                return 1;
            }
            if (i == tokens->size - 1) {
                fprintf(stderr, RED "replay: Error missing period argument\n" RESET "Usage: replay --command [STR] --interval [N] --period [N]\n");
                return 1;
            }
            hasPeriod = 1;
            for (int j = 0; j < strlen(tokens->arr[i + 1]); j++) {
                if (tokens->arr[i + 1][j] < '0' || tokens->arr[i + 1][j] > '9') {
                    fprintf(stderr, RED "replay: Error invalid period argument\n" RESET "Usage: replay --command [STR] --interval [N] --period [N]\n");
                    return 1;
                }
            }
            char *endPtr = NULL;
            errno = 0;
            period = strtol(tokens->arr[i + 1], &endPtr, 10);
            if (errno != 0 || endPtr == tokens->arr[i + 1]) {
                fprintf(stderr, RED "replay: Error invalid period argument\n" RESET "Usage: replay --command [STR] --interval [N] --period [N]\n");
                return 1;
            }
            i++;
        }
        else {
            fprintf(stderr, RED "replay: Error invalid argument\n" RESET "Usage: replay --command [STR] --interval [N] --period [N]\n");
            return 1;
        }
    }

    if (!hasCommand) {
        fprintf(stderr, RED "replay: Error missing command argument\n" RESET "Usage: replay --command [STR] --interval [N] --period [N]\n");
        return 1;
    }
    if (!hasInterval) {
        fprintf(stderr, RED "replay: Error missing interval argument\n" RESET "Usage: replay --command [STR] --interval [N] --period [N]\n");
        return 1;
    }
    if (!hasPeriod) {
        fprintf(stderr, RED "replay: Error missing period argument\n" RESET "Usage: replay --command [STR] --interval [N] --period [N]\n");
        return 1;
    }

    long num = period / interval;
    int currStatus = 0;
    pid_t childPid = fork();
    if (childPid < 0) {
        perror(RED "replay" RESET);
        return 1;
    }
    else if (childPid == 0) {
        signal(SIGINT, SIG_DFL);
        signal(SIGTSTP, SIG_DFL);
        if (setpgid(0, 0) == -1) {
            perror("setpgid");
            return 1;
        }
        for (long i = 0; i < num; i++) {
            vector *copy = NULL;
            init_vector(&copy);
            for (int j = 0; j < command->size; j++) copy->push_back(copy, command->arr[j]);
            currStatus |= parse_command(copy);
            sleep(interval);
            copy->erase(copy);
        }
        command->erase(command);
        exit(currStatus);
    }
    else {
        int statusCode = 0;
        jobs->insert(jobs, childPid, tokens->arr[0]);
        signal(SIGTTOU, SIG_IGN);
        signal(SIGTTIN, SIG_IGN);
        tcsetpgrp(STDIN_FILENO, childPid);

        waitpid(childPid, &statusCode, WUNTRACED);

        tcsetpgrp(STDIN_FILENO, getpgrp());

        if (!WIFSTOPPED(statusCode)) jobs->delete(jobs, childPid);
        else {
            if (WSTOPSIG(statusCode) == SIGTSTP) {
                job *curr = jobs->proc(jobs, childPid);
                printf("[%d] suspended %s [%d]\n", curr->jobNumber, curr->name, curr->pid);
            }
            currStatus = 1;
        }
        if (!WIFEXITED(statusCode)) currStatus = 1;
        signal(SIGTTOU, SIG_DFL);
        signal(SIGTTIN, SIG_DFL);
        command->erase(command);
        return currStatus;
    }
}
