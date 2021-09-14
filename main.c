#include <stdio.h>
#include "globals.h"
#include "processor/prompt.h"
#include "processor/init.h"
#include <stdlib.h>
#include <errno.h>
#include "utils/tokenize.h"
#include "utils/lists.h"
#include "utils/parse.h"

int main(void) {
    char *inputBuffer = NULL;
    initialize_shell();
    int status = 0;
    while (status != -1 && status != 5) {
        size_t inputLen = 0;
        display_prompt(0);
        if (getline(&inputBuffer, &inputLen, stdin) == -1) {
            perror("getline()");
            exit(errno);
        }
        list *tokens = tokenize_command(inputBuffer);
        status = parse_command(tokens);
        tokens->erase(tokens);
    }
    if (status == -1) {
        printf("NYASH: critical error. Exiting\n");
        return -1;
    }
    free(inputBuffer);
    return 0;
}
