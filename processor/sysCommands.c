#include "sysCommands.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

int exec_sys_command(list *tokens) {
    int bg = 0;
    if (strcmp(tokens->arr[tokens->size - 1], "&") == 0) {
        bg = 1;
        free(tokens->arr[tokens->size - 1]);
        tokens->arr[tokens->size - 1] = NULL;
    }
    else {
        tokens->append(tokens, NULL);
    }
    pid_t childPid = fork();
    int statusCode = 0;
    if (childPid == -1) {
        perror("fork()");
        return 1;
    }
    if (childPid == 0) {
        //child code
        setpgid(0, 0);
        if (execvp(tokens->arr[0], tokens->arr) == -1) {
            perror(tokens->arr[0]);
            return 1;
        }
    }
    else {
        signal(SIGTTOU, SIG_IGN);
        tcsetpgrp(0, childPid);
        waitpid(childPid, &statusCode, WUNTRACED);
        tcsetpgrp(0, getpgrp());
        signal(SIGTTOU, SIG_DFL);
    }
    return 0;
}
