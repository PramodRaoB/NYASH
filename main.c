#include "globals.h"
#include "processor/init.h"
#include "processor/prompt.h"
#include "utils/vector.h"
#include "utils/parse.h"
#include "utils/tokenize.h"
#include "processor/child_handler.h"
#include "commands/history.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

//TODO: Arrow-key history
//TODO: Relative path handling

int main(void) {
    char *inputBuffer = NULL;
    signal(SIGCHLD, child_handler);
    signal(SIGINT, SIG_IGN);
    signal(SIGTSTP, SIG_IGN);
    initialize_shell();
    int status = 0;
    while (status != -1) {
        size_t bufSize = 0;
        if (jobs->size == 0) {
           currJob = 1;
        }
        display_prompt(status);
        if (getline(&inputBuffer, &bufSize, stdin) == EOF) {
            status = -1;
            break;
        }
        insert_into_history(inputBuffer);
        write_into_history();
        vector *commands = tokenize_input(inputBuffer);
        if (!commands)
            continue;
        for (int i = 0; i < commands->size; i++) {
            vector *tokens = tokenize_command(commands->arr[i]);
            status = parse_command(tokens);
            tokens->erase(tokens);
        }
        commands->erase(commands);
        free(inputBuffer);
        inputBuffer = NULL;
    }
    signal(SIGINT, SIG_DFL);
    signal(SIGTSTP, SIG_DFL);
    signal(SIGCHLD, SIG_DFL);
    free(inputBuffer);
    free(HOME);
    free(currPath);
    free(prevPath);
    free(historyFilePath);
    historyList->erase(historyList);
    jobs->erase(jobs);
    exit(EXIT_SUCCESS);
}
