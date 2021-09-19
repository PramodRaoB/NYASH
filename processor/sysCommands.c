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
        perror("fork()");
        return 1;
    }
    if (childPid == 0) {
        //child code
        signal(SIGINT, SIG_DFL);
        signal(SIGSTOP, SIG_DFL);
        if (setpgid(0, 0) == -1) {
            perror("setpgid");
            return 1;
        }
        if (execvp(tokens->arr[0], tokens->arr) == -1) {
            printf("NYASH: command not found: %s\n", tokens->arr[0]);
            exit(1);
        }
    }
    else {
        if (bg) {
            printf("%d\n", childPid);
            jobs->insert(jobs, childPid, tokens->arr[0]);
            return 0;
        }
        signal(SIGTTOU, SIG_IGN);
        signal(SIGTTIN, SIG_IGN);
        if (tcsetpgrp(STDIN_FILENO, childPid) == -1) {
            perror("tcsetpgrp");
            signal(SIGTTOU, SIG_DFL);
            return 1;
        }
        waitpid(childPid, &statusCode, WUNTRACED);

        if (tcsetpgrp(STDIN_FILENO, getpgrp()) == -1) {
            perror("tcsetpgrp");
            signal(SIGTTOU, SIG_DFL);
            signal(SIGTTIN, SIG_DFL);
            return 1;
        }
        signal(SIGTTOU, SIG_DFL);
        signal(SIGTTIN, SIG_DFL);
    }
    return 0;
}
