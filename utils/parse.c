#include "parse.h"
#include "../globals.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../commands/pwd.h"
#include "../commands/echo.h"
#include "../commands/cd.h"
#include "../commands/ls.h"
#include "../commands/pinfo.h"
#include "../processor/sysCommands.h"
#include "../commands/repeat.h"
#include "../commands/history.h"
#include "../commands/jobs.h"
#include "../commands/sig.h"
#include "../commands/bg.h"
#include "../commands/fg.h"

char *builtinCommands[] = {"cd", "echo", "history", "ls", "pinfo", "pwd", "repeat", "_jobs", "exit"};
int is_builtin(vector *tokens) {
    if (!tokens) return 0;
    if (tokens->size == 0) return 0;
    if (!tokens->arr[0]) return 0;
    int n = sizeof (builtinCommands) / sizeof (char *);
    for (int i = 0; i < n; i++) {
        if (strcmp(builtinCommands[i], tokens->arr[0]) == 0) return 1;
    }
    return 0;
}

/*
 * If HOME is a prefix of the current path
 * return index (0-based) of the first character to be printed
 * after inserting ~
 * */
void parse_curr_dir(char *path) {
    size_t currLen = strlen(path);
    if (currLen < homeLen) return;
    int i;
    for (i = 0; i < homeLen; i++) {
        if (HOME[i] != path[i]) return;
    }
    sprintf(path, "~%s", path + i);
}

char *expand_path(char *path) {
    char *finalPath;
    if (path == NULL) return NULL;
    if (strlen(path) == 1 && path[0] == '~') {
        finalPath = (char *) malloc(strlen(HOME) + 1);
        strcpy(finalPath, HOME);
        return finalPath;
    }
    if (strlen(path) == 2 && path[0] == '~' && path[1] == '/') {
        finalPath = (char *) malloc(strlen(HOME) + 1);
        strcpy(finalPath, HOME);
        return finalPath;
    }
    if (strlen(path) > 2 && path[0] == '~' && path[1] == '/') {
        finalPath = (char *) malloc(strlen(HOME) + strlen(path));
        strcpy(finalPath, HOME);
        strcat(finalPath, path + 1);
        return finalPath;
    }
    finalPath = (char *) malloc(strlen(path) + 1);
    strcpy(finalPath, path);
    return finalPath;
}

void reset_io(int inputFd, int outputFd) {
    dup2(inputFd, STDIN_FILENO);
    dup2(outputFd, STDOUT_FILENO);
    close(inputFd);
    close(outputFd);
}

int parse_command(vector *tokens) {
    if (tokens == NULL) return 1;
    if (tokens->size == 0) return 1;

    int inputFd = dup(STDIN_FILENO);
    int outputFd = dup(STDOUT_FILENO);
    if (inputFd < 0 || outputFd < 0) {
        printf(RED "NYASH: Error with file descriptor\n" RESET);
        return 1;
    }

    vector *processedTokens = NULL;
    int usePipe = 1;
    init_vector(&processedTokens);
    int currStatus = 0;
    for (int i = 0; i < tokens->size; i++) {
        if (strcmp(tokens->arr[i], "<") == 0) {
            if (i == tokens->size - 1) {
                printf(RED "NYASH: Error invalid input file\n" RESET);
                reset_io(inputFd, outputFd);
                return 1;
            }
            int fd = open(tokens->arr[i + 1], O_RDONLY);
            if (fd < 0) {
                reset_io(inputFd, outputFd);
                perror("NYASH");
                return 1;
            }
            if (dup2(fd, STDIN_FILENO) < 0) {
                reset_io(inputFd, outputFd);
                return 1;
            }
            close(fd);
            i++;
        }
        else if (strcmp(tokens->arr[i], ">") == 0) {
            if (i == tokens->size - 1) {
                printf(RED "NYASH: Error invalid output file\n" RESET);
                reset_io(inputFd, outputFd);
                return 1;
            }
            int fd = open(tokens->arr[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (fd < 0) {
                reset_io(inputFd, outputFd);
                perror("NYASH");
                return 1;
            }
            if (dup2(fd, STDOUT_FILENO) < 0) {
                reset_io(inputFd, outputFd);
                return 1;
            }
            usePipe = 0;
            close(fd);
            i++;
        }
        else if (strcmp(tokens->arr[i], ">>") == 0) {
            if (i == tokens->size - 1) {
                printf(RED "NYASH: Error invalid output file\n" RESET);
                reset_io(inputFd, outputFd);
                return 1;
            }
            int fd = open(tokens->arr[i + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
            if (fd < 0) {
                reset_io(inputFd, outputFd);
                perror("NYASH");
                return 1;
            }
            if (dup2(fd, STDOUT_FILENO) < 0) {
                reset_io(inputFd, outputFd);
                return 1;
            }
            usePipe = 0;
            close(fd);
            i++;
        }
        else if (strcmp(tokens->arr[i], "|") == 0) {
            currStatus |= execute_command(processedTokens, usePipe);
            processedTokens->clear(processedTokens);
            usePipe = 1;
            if (dup2(outputFd, STDOUT_FILENO) < 0) {
                perror("Output stream");
                return 1;
            }
        }
        else {
            processedTokens->push_back(processedTokens, tokens->arr[i]);
        }
    }
    /*
     * open pipe
     * stdout point to pipe[1]
     * close pipe[1]
     * run the function
     * stdin point to pipe[0]
     * close pipe[0]
     * */
    currStatus |= execute_command(processedTokens, 0);

    processedTokens->erase(processedTokens);
    reset_io(inputFd, outputFd);
    return currStatus;
}

int execute_command(vector *tokens, int usePipe) {
    int currStatus = 0;
    int pfd[2] = {-1, -1};
    pipe(pfd);
    if (usePipe) {
        if (dup2(pfd[1], STDOUT_FILENO) < 0) {
            perror("pipe");
            return 1;
        }
    }
    close(pfd[1]);

    if (strcmp(tokens->arr[0], "pwd") == 0) {
        currStatus = pwd(tokens);
    }
    else if (strcmp(tokens->arr[0], "echo") == 0)
        currStatus = echo(tokens);
    else if (strcmp(tokens->arr[0], "cd") == 0)
        currStatus = cd(tokens);
    else if (strcmp(tokens->arr[0], "ls") == 0)
        currStatus = ls(tokens);
    else if (strcmp(tokens->arr[0], "pinfo") == 0)
        currStatus = pinfo(tokens);
    else if (strcmp(tokens->arr[0], "repeat") == 0)
        currStatus = repeat(tokens);
    else if (strcmp(tokens->arr[0], "history") == 0)
        currStatus = history(tokens);
    else if (strcmp(tokens->arr[0], "jobs") == 0)
        currStatus = _jobs(tokens);
    else if (strcmp(tokens->arr[0], "sig") == 0)
        currStatus = sig(tokens);
    else if (strcmp(tokens->arr[0], "fg") == 0)
        currStatus = fg(tokens);
    else if (strcmp(tokens->arr[0], "bg") == 0)
        currStatus = bg(tokens);
    else if (strcmp(tokens->arr[0], "exit") == 0)
        currStatus = -1;
    else
        currStatus = exec_sys_command(tokens);

    if (dup2(pfd[0], STDIN_FILENO) < 0) {
        perror("STDIN");
        return 1;
    }
    close(pfd[0]);
    return currStatus;
}