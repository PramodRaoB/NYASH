#include "child_handler.h"
#include <stdio.h>
#include "../globals.h"

void child_handler(int signum) {
    int waitStatus = 0, statusCode = 0;
    pid_t childPid;
    while ((childPid = waitpid(-1, &waitStatus, WNOHANG | WUNTRACED | WCONTINUED)) > 0) {
        char *childName = jobs->find(jobs, childPid);
        if (!childName) continue;
        if (WIFEXITED(waitStatus)) {
            printf("%s with pid %d exited normally\n", childName, childPid);
            jobs->delete(jobs, childPid);
        } else if (WIFSTOPPED(waitStatus)) {
            printf("%s with pid %d suspended normally\n", childName, childPid);
        } else if (WIFCONTINUED(waitStatus)) {
            printf("%s with pid %d continued normally\n", childName, childPid);
        } else {
            printf("%s with pid %d exited abnormally\n", childName, childPid);
            jobs->delete(jobs, childPid);
            statusCode = 1;
        }
    }
}
