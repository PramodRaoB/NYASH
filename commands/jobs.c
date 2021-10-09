#include "jobs.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <getopt.h>
#include "pinfo.h"
#include "../utils/tokenize.h"

int qsort_compare(const void *x,const void *y) {
    char *a = *((char **) x);
    a = jobs->find(jobs, atoi(a));
    char *b = *((char **) y);
    b = jobs->find(jobs, atoi(b));
    return strcmp(a, b);
}

int _jobs(vector *tokens) {
    optind = 0;
    int opt, flagR = 0, flagS = 0;
    while ((opt = getopt(tokens->size, tokens->arr, ":rs")) != -1) {
        switch (opt) {
            case 'r':
                flagR = 1;
                break;
            case 's':
                flagS = 1;
                break;
            default:
                fprintf(stderr, RED "jobs: Error invalid argument\n" RESET "Usage: jobs -[rs]\n");
                return 1;
        }
    }
    if (!flagR && !flagS) flagR = flagS = 1;

    vector *currJobs = NULL;
    init_vector(&currJobs);
    job *temp = jobs->start;
    while (temp != NULL) {
        char pid[8];
        sprintf(pid, "%d", temp->pid);
        currJobs->push_back(currJobs, pid);
        temp = temp->next;
    }
    if (currJobs->size == 0) {
        currJobs->erase(currJobs);
        return 0;
    }
    qsort(currJobs->arr, currJobs->size, sizeof (currJobs->arr[0]), qsort_compare);
    for (int i = 0; i < currJobs->size; i++) {
        job *curr = jobs->proc(jobs, atoi(currJobs->arr[i]));
        char *procStat = (char *) malloc(20);
        if (!procStat) {
            perror("pinfo");
            return 1;
        }
        sprintf(procStat, "/proc/%d/stat", curr->pid);
        FILE *status = fopen(procStat, "r");
        if (status == NULL) {
            fprintf(stderr, RED "jobs: Error process not found\n" RESET);
            free(procStat);
            continue;
        }

        char *data = NULL;
        size_t dataSize = 0;
        if (getline(&data, &dataSize, status) == -1) {
            perror("jobs");
            free(data);
            free(procStat);
            continue;
        }
        fclose(status);

        vector *statArgs = tokenize_command(data);
        if (statArgs == NULL) {
            free(data);
            free(procStat);
            continue;
        }
        //man 5 proc

        char jobStatus[10];
        strcpy(jobStatus, "continue");
        if (statArgs->arr[2][0] == 'T' && flagS)
            strcpy(jobStatus, "Stopped");
        if (statArgs->arr[2][0] != 'T' && flagR)
            strcpy(jobStatus, "Running");
        if (strcmp(jobStatus, "continue") != 0)
            printf("[%d] %s %s [%d]\n", curr->jobNumber, jobStatus, curr->name, curr->pid);

        statArgs->erase(statArgs);
        free(data);
        free(procStat);
    }
    currJobs->erase(currJobs);
    return 0;
}
