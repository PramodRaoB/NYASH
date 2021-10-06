#include "child_handler.h"
#include <stdio.h>
#include "../globals.h"

void child_handler(int signum) {
    int waitStatus = 0;
    pid_t childPid;
    while ((childPid = waitpid(-1, &waitStatus, WNOHANG | WUNTRACED | WCONTINUED)) > 0) {
        job *curr = jobs->proc(jobs, childPid);
        if (!curr) continue;
        if (WIFEXITED(waitStatus)) {
            printf(GREEN "[%d] %s with pid [%d] exited normally\n" RESET, curr->jobNumber, curr->name, curr->pid);
            jobs->delete(jobs, childPid);
        } else if (WIFSTOPPED(waitStatus)) {
            printf("[%d] %s with pid [%d] suspended normally\n", curr->jobNumber, curr->name, curr->pid);
        } else if (WIFCONTINUED(waitStatus)) {
            printf("[%d] %s with pid [%d] continued normally\n", curr->jobNumber, curr->name, curr->pid);
        } else {
            printf(RED "[%d] %s with pid [%d] exited abnormally\n" RESET, curr->jobNumber, curr->name, curr->pid);
            jobs->delete(jobs, childPid);
        }
    }
}
