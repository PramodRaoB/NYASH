#include "baywatch.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <termios.h>
#include "../globals.h"
#include "../utils/tokenize.h"

static void die(const char *s) {
    perror(s);
    exit(1);
}

struct termios orig_termios;

static void disableRawMode() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

/**
 * Enable row mode for the terminal
 * The ECHO feature causes each key you type to be printed to the terminal, so you can see what you’re typing.
 * Terminal attributes can be read into a termios struct by tcgetattr().
 * After modifying them, you can then apply them to the terminal using tcsetattr().
 * The TCSAFLUSH argument specifies when to apply the change: in this case, it waits for all pending output to be written to the terminal, and also discards any input that hasn’t been read.
 * The c_lflag field is for “local flags”
 */
static void enableRawMode() {
    if (tcgetattr(STDIN_FILENO, &orig_termios) == -1) die("tcgetattr");
    atexit(disableRawMode);
    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ICANON | ECHO);
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1) die("tcsetattr");
}

static int print_interrupt(int first) {
    char *line[3] = {NULL, NULL, NULL};
    FILE *interruptFile = fopen("/proc/interrupts", "r");
    if (interruptFile == NULL) {
        perror("baywatch");
        return 1;
    }
    size_t sz[3] = {0, 0, 0};
    for (int i = 0; i < 3; i++) {
        if (getline(&line[i], &sz[i], interruptFile) == -1) {
            perror("baywatch");
            fclose(interruptFile);
            return 1;
        }
    }
    fclose(interruptFile);
    vector *l1 = tokenize_command(line[0]);
    if (!l1) {
        fprintf(stderr, "baywatch: Error reading /proc/interrupts\n" RESET);
        return 1;
    }
    if (first) {
        for (int i = 0; i < l1->size; i++) {
            printf("      %s", l1->arr[i]);
        }
        printf("\n");
    }
    vector *l2 = tokenize_command(line[2]);
    if (!l2) {
        fprintf(stderr, "baywatch: Error reading /proc/interrupts\n" RESET);
        return 1;
    }
    for (int i = 1; i <= l1->size; i++) {
        char *endPtr = NULL;
        long curr = strtol(l2->arr[i], &endPtr, 10);
        printf("%10ld", curr);
    }
    printf("\n");

    for (int i = 0; i < 3; i++) free(line[i]);
    l1->erase(l1);
    l2->erase(l2);
    return 0;
}

static int print_newborn() {
    FILE *newbornFile = fopen("/proc/loadavg", "r");
    if (newbornFile == NULL) {
        perror("baywatch");
        return 1;
    }
    char *line = NULL;
    size_t sz = 0;
    if (getline(&line, &sz, newbornFile) == -1) {
        perror("baywatch");
        fclose(newbornFile);
        return 1;
    }
    fclose(newbornFile);
    vector *args = tokenize_command(line);
    if (!args) {
        fprintf(stderr, "baywatch: Error reading /proc/loadavg\n" RESET);
        return 1;
    }
    printf("%s\n", args->arr[args->size - 1]);

    free(line);
    args->erase(args);
    return 0;
}

static int print_dirty() {
    FILE *dirtyFile = fopen("/proc/meminfo", "r");
    if (dirtyFile == NULL) {
        perror("baywatch");
        return 1;
    }
    char *line = NULL;
    size_t sz = 0;
    for (int i = 0; i < 17; i++) {
        free(line);
        line = NULL;
        sz = 0;
        if (getline(&line, &sz, dirtyFile) == -1) {
            perror("baywatch");
            fclose(dirtyFile);
            return 1;
        }
    }
    fclose(dirtyFile);
    vector *data = tokenize_command(line);
    printf("%s %s\n", data->arr[1], data->arr[2]);
    data->erase(data);
    free(line);
}

int baywatch(vector *tokens) {
    optind = 0;
    int opt = 0;
    long interval = -1;
    while ((opt = getopt(tokens->size, tokens->arr, ":n:")) != -1) {
        if (opt == 'n') {
            if (optarg == NULL) {
                fprintf(stderr, RED "baywatch: Error invalid interval\n" RESET);
                return 1;
            }
            else {
                for (int i = 0; i < strlen(optarg); i++) {
                    if (optarg[i] < '0' || optarg[i] > '9') {
                        fprintf(stderr, RED "baywatch: Error invalid interval\n" RESET);
                        return 1;
                    }
                }
                errno = 0;
                char *endPtr = NULL;
                interval = strtol(optarg, &endPtr, 10);
                if (errno != 0 || optarg == endPtr) {
                    fprintf(stderr, RED "baywatch: Error invalid interval\n" RESET);
                    return 1;
                }
                if (interval <= 0) {
                    fprintf(stderr, RED "baywatch: Error invalid interval\n" RESET "Interval needs to be a positive integer\n");
                    return 1;
                }
            }
        }
        else {
            fprintf(stderr, RED "baywatch: Error invalid flag specified\n" RESET "Usage: baywatch [OPTIONS] <command>\n");
            return 1;
        }
    }
    if (interval <= 0) {
        fprintf(stderr, RED "baywatch: Error invalid interval\n" RESET "Interval needs to be a positive integer\n");
        return 1;
    }
    int mode = -1;
    for (; optind < tokens->size; optind++) {
        if (!strcmp(tokens->arr[optind], "interrupt")) {
            if (mode != -1) {
                fprintf(stderr, RED "baywatch: Error multiple commands found\n" RESET "Usage: baywatch [OPTIONS] <command>\n");
                return 1;
            }
            else mode = 1;
        }
        else if (!strcmp(tokens->arr[optind], "newborn")) {
            if (mode != -1) {
                fprintf(stderr, RED "baywatch: Error multiple commands found\n" RESET "Usage: baywatch [OPTIONS] <command>\n");
                return 1;
            }
            else mode = 2;
        }
        else if (!strcmp(tokens->arr[optind], "dirty")) {
            if (mode != -1) {
                fprintf(stderr, RED "baywatch: Error multiple commands found\n" RESET "Usage: baywatch [OPTIONS] <command>\n");
                return 1;
            }
            else mode = 3;
        }
        else {
            fprintf(stderr, RED "baywatch: Error invalid command %s\n" RESET, tokens->arr[optind]);
            return 1;
        }
    }
    if (mode == -1) {
        fprintf(stderr, RED "baywatch: Error missing command\n" RESET "Usage: baywatch [OPTIONS] <command>\n");
        return 1;
    }

    int currStatus = 0;
    pid_t childPid = fork();
    if (childPid < 0) {
        perror(RED "baywatch" RESET);
        return 1;
    }
    else if (childPid == 0) {
        signal(SIGINT, SIG_DFL);
        signal(SIGTSTP, SIG_DFL);
        if (setpgid(0, 0) == -1) {
            perror("baywatch");
            return 1;
        }
        int first = 1;
        while (currStatus == 0) {
            switch(mode) {
                case 1:
                    currStatus |= print_interrupt(first);
                    first = 0;
                    break;
                case 2:
                    currStatus |= print_newborn();
                    break;
                case 3:
                    currStatus |= print_dirty();
                    break;
                default:
                    break;
            }
            sleep(interval);
        }
        exit(currStatus);
    }
    else {
        char c;
        setbuf(stdout, NULL);
        enableRawMode();
        while (read(STDIN_FILENO, &c, 1) == 1) {
            if (c == 'q') {
                kill(childPid, SIGTERM);
                break;
            }
        }
        disableRawMode();
        return currStatus;
    }
}