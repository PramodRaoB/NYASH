#include "history.h"
#include <stdlib.h>
#include <pwd.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "../globals.h"

char *historyFilePath = NULL;
header *historyList = NULL;

#define min(a, b) (((a) < (b)) ? (a) : (b))

int history_init(void) {
    char *homeDir = getenv("HOME");
    if (!homeDir) {
        homeDir = getpwuid(getuid())->pw_dir;
        if (!homeDir) {
            perror("history_init");
            return 1;
        }
    }
    historyFilePath = (char *) malloc(PATH_MAX + 20);
    if (!historyFilePath) {
        perror("history_init");
        return 1;
    }
    sprintf(historyFilePath, "%s/.nyash_history", homeDir);
    int fd = open(historyFilePath, O_CREAT | O_RDONLY, 0600);
    if (fd < 0) {
        perror("history_init");
        return 1;
    }
    close(fd);
    FILE *historyFile = fopen(historyFilePath, "r");
    if (historyFile == NULL) {
        perror("history_init");
        return 1;
    }
    char *charBuffer = NULL;
    if (init_list(&historyList)) {
        fclose(historyFile);
        return 1;
    }
    size_t len = 0;
    size_t nread = 0;
    while ((nread = getline(&charBuffer, &len, historyFile)) != -1) {
        charBuffer[nread - 1] = '\0';
        historyList->insert(historyList, charBuffer);
        free(charBuffer);
        charBuffer = NULL;
        len = 0;
    }

    fclose(historyFile);
    free(charBuffer);
    return 0;
}

int history(vector *tokens)  {
    int printNum = 0;
    if (tokens->size == 1)
        printNum = 10;
    else if (tokens->size == 2) {
        for (int i = 0; i < strlen(tokens->arr[1]); i++) {
            if (tokens->arr[1][i] < '0' || tokens->arr[1][i] > '9') {
                printf(RED "Usage: history [0 <= N <= 20]\n" RESET);
                return 1;
            }
        }
        printNum = atoi(tokens->arr[1]);
    }
    else {
        printf(RED "Usage: history [0 <= N <= 20]\n" RESET);
        return 1;
    }
    if (printNum < 0 || printNum > 20) {
        printf(RED "Argument must be in range [0, 20]" RESET);
        return 1;
    }
    list *curr = historyList->start;
    int toPrint = min(printNum, historyList->size);
    int toSkip = historyList->size - toPrint;
    while (toSkip--) {
        curr = curr->next;
    }
    while (toPrint--) {
        printf("%s\n", curr->str);
        curr = curr->next;
    }
    return 0;
}

int insert_into_history(vector *tokens) {
    int totalSize = 0;
    for (int i = 0; i < tokens->size; i++) totalSize += strlen(tokens->arr[i]) + 1;
    char *command = (char *) malloc(totalSize + 1);
    if (!command) {
        perror("insert_into_history");
        return 1;
    }
    command[0] = '\0';
    for (int i = 0; i < tokens->size; i++) {
        strcat(command, tokens->arr[i]);
        strcat(command, " ");
    }

    if (historyList->size == 0) {
        historyList->insert(historyList, command);
    }
    else {
        list *curr = historyList->start;
        while (curr->next) curr = curr->next;
        if (strcmp(command, curr->str) != 0) historyList->insert(historyList, command);
    }
    if (historyList->size > 20) historyList->trim(historyList);
    free(command);
    return 0;
}

int write_into_history(void) {
    int fd = open(historyFilePath, O_CREAT | O_TRUNC | O_RDWR, 0600);
    if (fd < 0) {
        perror("write_into_history");
        return 1;
    }
    list *curr = historyList->start;
    while (curr) {
        write(fd, curr->str, strlen(curr->str));
        write(fd, "\n", 1);
        curr = curr->next;
    }
    close(fd);
    return 0;
}