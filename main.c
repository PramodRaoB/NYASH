#include <stdio.h>
#include "globals.h"
#include "processor/prompt.h"
#include "processor/init.h"
#include <stdlib.h>
#include <errno.h>
#include "utils/tokenize.h"
#include "utils/lists.h"

int main(void) {
    char *inputBuffer = NULL;
    initialize_shell();
    while (1) {
        size_t inputLen = 0;
        display_prompt(0);
        if (getline(&inputBuffer, &inputLen, stdin) == -1) {
            perror("getline()");
            exit(errno);
        }
        list *tok = tokenize_command(inputBuffer);
        tok->erase(tok);
    }
    free(inputBuffer);
    return 0;
}
