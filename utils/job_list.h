#ifndef NYASH_JOB_LIST_H
#define NYASH_JOB_LIST_H

typedef struct JobList jobList;
typedef struct Job job;

struct JobList {
    int size;
    job *start;

    int (*insert)(jobList *, int, char *);
    char *(*find)(jobList *, int);
    int (*delete)(jobList *, int);
    void (*erase)(jobList *);
};

struct Job {
    int pid;
    char *name;
    job *next;
};

int init_jobs(jobList **h);
job *create_job(int pid, char *name);
int insert_job(jobList *h, int pid, char *name);
char *find_job(jobList *h, int pid);
int delete_job(jobList *h, int pid);
void erase_jobs(jobList *h);

#endif //NYASH_JOB_LIST_H
