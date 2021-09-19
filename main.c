#include "globals.h"
#include "processor/init.h"
#include "processor/prompt.h"
#include "utils/vector.h"
#include "utils/parse.h"
#include "utils/tokenize.h"
#include "processor/child_handler.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

//TODO: error-handling. mem-leak
//TODO: colors
//TODO: ls year thing
//TODO: Arrow-key history?

int main(void) {
    char *inputBuffer = NULL;
    signal(SIGCHLD, child_handler);
    signal(SIGINT, SIG_IGN);
    signal(SIGTSTP, SIG_IGN);
    initialize_shell();
    int status = 0;
    while (status != -1 && status != 5) {
        size_t bufSize = 0;
        display_prompt(0);
        if (getline(&inputBuffer, &bufSize, stdin) == -1) {
            perror("main");
            exit(EXIT_FAILURE);
        }
        vector *commands = tokenize_input(inputBuffer);
        if (!commands)
            continue;
        for (int i = 0; i < commands->size; i++) {
            vector *tokens = tokenize_command(commands->arr[i]);
            status = parse_command(tokens);
            tokens->erase(tokens);
        }
        commands->erase(commands);
    }
    signal(SIGINT, SIG_DFL);
    signal(SIGTSTP, SIG_DFL);
    signal(SIGCHLD, SIG_DFL);
    if (status == -1) {
        exit(EXIT_FAILURE);
    }
    free(inputBuffer);
    return 0;
}
