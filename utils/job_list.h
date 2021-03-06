#ifndef NYASH_JOB_LIST_H
#define NYASH_JOB_LIST_H

typedef struct JobList jobList;
typedef struct Job job;

struct JobList {
    int size;
    job *start;

    int (*insert)(jobList *, int, char *);
    char *(*find)(jobList *, int);
    int (*find_by_number)(jobList *, int);
    job *(*proc)(jobList *, int);
    int (*delete)(jobList *, int);
    void (*erase)(jobList *);
};

struct Job {
    int pid;
    char *name;
    int jobNumber;
    job *next;
};

void init_jobs(jobList **h);
job *create_job(int pid, char *name);
int insert_job(jobList *h, int pid, char *name);
char *find_job(jobList *h, int pid);
int find_job_by_number(jobList *h, int num);
job *proc_job(jobList *h, int pid);
int delete_job(jobList *h, int pid);
void erase_jobs(jobList *h);

#endif //NYASH_JOB_LIST_H
