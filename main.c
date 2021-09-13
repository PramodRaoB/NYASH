#include <stdio.h>
#include "globals.h"
#include "processor/prompt.h"
#include "processor/init.h"
#include <stdlib.h>
#include <errno.h>

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
        printf("typed: %s\n", inputBuffer);
    }
    free(inputBuffer);
    return 0;
}
