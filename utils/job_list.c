#include "job_list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../globals.h"

void init_jobs(jobList **h) {
    *h = (jobList *) malloc(sizeof(jobList));
    if (!(*h)) {
        perror("init_jobs");
        exit(EXIT_FAILURE);
    }
    (*h)->size = 0;
    (*h)->start = NULL;
    (*h)->insert = insert_job;
    (*h)->find = find_job;
    (*h)->find_by_number = find_job_by_number;
    (*h)->delete = delete_job;
    (*h)->erase = erase_jobs;
    (*h)->proc = proc_job;
}

job *create_job(int pid, char *name) {
    if (name == NULL) return NULL;
    job *newNode = (job *) malloc(sizeof(job));
    if (!newNode) {
        perror("create_job");
        return NULL;
    }
    newNode->next = NULL;
    newNode->name = (char *) malloc(strlen(name) + 1);
    if (!(newNode->name)) {
        perror("create_job");
        return NULL;
    }
    strcpy(newNode->name, name);
    if (!(newNode->name)) {
        perror("create_name");
        return NULL;
    }
    newNode->pid = pid;
    newNode->jobNumber = currJob++;
    return newNode;
}

int insert_job(jobList *h, int pid, char *name) {
    job *node = create_job(pid, name);
    if (!node) return 1;
    h->size++;
    job *curr = h->start;
    node->next = NULL;
    if (!curr) {
        h->start = node;
        return 0;
    }
    while (curr->next) curr = curr->next;
    curr->next = node;
    return 0;
}

char *find_job(jobList *h, int pid) {
    if (!h) return NULL;
    job *curr = h->start;
    while (curr) {
        if (curr->pid == pid) return curr->name;
        curr = curr->next;
    }
    return NULL;
}

int find_job_by_number(jobList *h, int num) {
    if (!h) return -1;
    job *curr = h->start;
    while (curr) {
        if (curr->jobNumber == num) return curr->pid;
        curr = curr->next;
    }
    return -1;
}

job *proc_job(jobList *h, int pid) {
    if (!h) return NULL;
    job *curr = h->start;
    while (curr) {
        if (curr->pid == pid) return curr;
        curr = curr->next;
    }
    return NULL;
}

int delete_job(jobList *h, int pid) {
    if (!h) return 1;
    if (h->size == 0) return 1;
    if (pid == h->start->pid) {
        job *temp = h->start;
        h->start = h->start->next;
        free(temp->name);
        free(temp);
        h->size--;
        return 0;
    }
    job *curr = h->start->next;
    job *prev = h->start;
    while (curr) {
        if (pid == curr->pid) {
            prev->next = curr->next;
            free(curr->name);
            free(curr);
            return 0;
        }
        prev = curr;
        curr = curr->next;
    }
    return 1;
}

void erase_jobs(jobList *h) {
    if (!h) return;
    job *temp = h->start;
    while (temp != NULL) {
        job *next = temp->next;
        free(temp);
        temp = next;
    }
    free(h);
}
