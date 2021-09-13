#include "prompt.h"
#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>
#include <assert.h>

void display_prompt(int status) {
    struct passwd *puid = getpwuid(getuid());
    assert(puid != NULL);
}
