#include "globals.h"
#include "processor/init.h"
#include "processor/prompt.h"
#include "utils/vector.h"
#include "utils/parse.h"
#include "utils/tokenize.h"
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char *inputBuffer = NULL;
  signal(SIGINT, SIG_IGN);
  signal(SIGTSTP, SIG_IGN);
  initialize_shell();
  int status = 0;
  while (status != -1 && status != 5) {
    size_t inputLen = 0;
    display_prompt(0);
    if (getline(&inputBuffer, &inputLen, stdin) == -1) {
      perror("getline()");
      exit(errno);
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
  if (status == -1) {
    printf("NYASH: critical error. Exiting\n");
    return -1;
  }
  free(inputBuffer);
  return 0;
}
