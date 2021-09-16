#include "sysCommands.h"
#include <unistd.h>
#include <stdio.h>

int exec_sys_command(char *command, char *argv[]) {
    if (!command) return 1;
    pid_t childPid = fork();
    if (childPid == -1) {
        perror("fork()");
        return 1;
    }
    if (childPid == 0) {
        //child code
        if (execvp(command, argv) == -1) {
            perror(command);
            return 1;
        }
    }
    return 0;
}
