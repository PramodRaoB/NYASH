#include "sysCommands.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include "../globals.h"

int exec_sys_command(vector *tokens) {
    int bg = 0;
    if (strcmp(tokens->arr[tokens->size - 1], "&") == 0) {
        bg = 1;
        free(tokens->arr[tokens->size - 1]);
        tokens->arr[tokens->size - 1] = NULL;
    }
    else {
        tokens->push_back(tokens, NULL);
    }
    pid_t childPid = fork();
    int statusCode = 0;
    if (childPid == -1) {
        perror("fork");
        return 1;
    }
    if (childPid == 0) {
        //child code
        signal(SIGINT, SIG_DFL);
        signal(SIGTSTP, SIG_DFL);
        if (setpgid(0, 0) == -1) {
            perror("setpgid");
            return 1;
        }
        if (execvp(tokens->arr[0], tokens->arr) == -1) {
            printf("NYASH: command not found: %s\n", tokens->arr[0]);
            free(HOME);
            free(currPath);
            free(prevPath);
            free(historyFilePath);
            historyList->erase(historyList);
            jobs->erase(jobs);
            exit(EXIT_FAILURE);
        }
    }
    else {
        jobs->insert(jobs, childPid, tokens->arr[0]);
        if (bg) {
            printf("%d\n", childPid);
            return 0;
        }
        signal(SIGTTOU, SIG_IGN);
        signal(SIGTTIN, SIG_IGN);
        tcsetpgrp(STDIN_FILENO, childPid);

        waitpid(childPid, &statusCode, WUNTRACED);

        tcsetpgrp(STDIN_FILENO, getpgrp());

        int currStatus = 0;
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
        return currStatus;
    }
    return 0;
}
