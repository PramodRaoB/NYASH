#include <stdio.h>
#include <unistd.h>
#include <malloc.h>
#include <assert.h>
#include "globals.h"
#include <limits.h>
#include "processor/prompt.h"
#include "processor/init.h"

int main(void) {
    initialize_shell();
    display_prompt(0);
    return 0;
}
