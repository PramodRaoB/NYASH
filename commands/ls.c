#include "ls.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "../globals.h"
#include "../utils/parse.h"
#include <pwd.h>
#include <grp.h>
#include <time.h>

int ls_processDir(char *path, int flagA, int flagL) {
    char *processedPath = expand_path(path);
    if (processedPath == NULL) return 1;
    DIR *fDir = opendir(processedPath);
    if (fDir == NULL) {
        perror("opendir()");
        return 1;
    }
    struct dirent *entry = NULL;
    char *filePath = (char *) malloc(PATH_MAX);
    struct stat statBuff;

    while ((entry = readdir(fDir))) {
        if (!flagA && entry->d_name[0] == '.') continue;
        sprintf(filePath, "%s/%s", path, entry->d_name);
        if (filePath == NULL) {
            perror("sprintf()");
            return 1;
        }

        if (flagL) {
            if (lstat(filePath, &statBuff) == -1) {
                perror("stat()");
                return 1;
            }

            //permission field
            printf((S_ISDIR(statBuff.st_mode)) ? "d" : "-");
            printf((statBuff.st_mode & S_IRUSR) ? "r" : "-");
            printf((statBuff.st_mode & S_IWUSR) ? "w" : "-");
            printf((statBuff.st_mode & S_IXUSR) ? "x" : "-");
            printf((statBuff.st_mode & S_IRGRP) ? "r" : "-");
            printf((statBuff.st_mode & S_IWGRP) ? "w" : "-");
            printf((statBuff.st_mode & S_IXGRP) ? "x" : "-");
            printf((statBuff.st_mode & S_IROTH) ? "r" : "-");
            printf((statBuff.st_mode & S_IWOTH) ? "w" : "-");
            printf((statBuff.st_mode & S_IXOTH) ? "x" : "-");

            //number of hard links
            printf(" %ld ", statBuff.st_nlink);

            //owner username
            printf("%s ", getpwuid(statBuff.st_uid)->pw_name);

            //group name
            printf("%s ", getgrgid(statBuff.st_gid)->gr_name);

            //file size
            printf("%ld ", statBuff.st_size);

            //last modified time
            //statBuff-st_mtim.tv_sec contains last modified time in seconds since epoch
            //localtime() converts it into tm struct
            //strftime() formats time from tm struct
            //printf("%ld ", statBuff.st_mtim.tv_sec);
            char formattedTime[25];
            long timeSinceEpoch = statBuff.st_mtim.tv_sec;
            strftime(formattedTime, 25, "%b %d %H:%M", localtime(&timeSinceEpoch));
            printf("%s ", formattedTime);
        }

        printf("%s", entry->d_name);
        if (flagL) printf("\n");
        else printf(" ");
    }
    if (!flagL) printf("\n");
    free(processedPath);
    return 0;
}

int ls(list *tokens) {
    optind = 0;
    int opt = 0, flagL = 0, flagA = 0;
    while ((opt = getopt(tokens->size, tokens->arr, ":la")) != -1) {
        switch (opt) {
            case 'l':
                flagL = 1;
                break;
            case 'a':
                flagA = 1;
                break;
            default:
                printf("ls: Usage ls -[al] ... [FILE]\n");
                return 1;
        }
    }

    int hasArgs = 0, statusCode = 0;
    for (; optind < tokens->size; optind++) {
        hasArgs = 1;
        statusCode |= ls_processDir(tokens->arr[optind], flagA, flagL);
    }
    if (!hasArgs) statusCode |= ls_processDir(".", flagA, flagL);
    return statusCode;
}
