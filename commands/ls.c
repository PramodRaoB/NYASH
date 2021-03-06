#include "ls.h"
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <malloc.h>
#include "../globals.h"
#include <pwd.h>
#include <grp.h>
#include <errno.h>
#include <time.h>

int print_total(char *path, int flagA) {
    DIR *fDir = opendir(path);
    if (fDir == NULL) {
        perror("ls");
        return 1;
    }
    long total = 0;
    struct dirent *entry = NULL;
    char *filePath = (char *) malloc(PATH_MAX);
    struct stat statBuff;

    errno = 0;
    while ((entry = readdir(fDir))) {
        if (!flagA && entry->d_name[0] == '.') continue;
        sprintf(filePath, "%s/%s", path, entry->d_name);
        if (filePath == NULL) {
            perror("ls");
            closedir(fDir);
            free(filePath);
            return 1;
        }

        if (lstat(filePath, &statBuff) == -1) {
            perror("ls");
            closedir(fDir);
            free(filePath);
            return 1;
        }

        total += statBuff.st_blocks;
    }
    if (errno != 0) {
        perror("ls");
        closedir(fDir);
        free(filePath);
        return 1;
    }
    printf("Total: %ld\n", total / 2);
    closedir(fDir);
    free(filePath);
    return 0;
}

int ls_l_info(char *path) {
    struct stat statBuff;
    //lstat as opposed to stat to handle symlinks
    if (lstat(path, &statBuff) == -1) {
        perror("stat()");
        return 1;
    }

    //permission field
    if (S_ISDIR(statBuff.st_mode)) printf("d");
    else if (S_ISLNK(statBuff.st_mode)) printf("l");
    else printf("-");
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
    time_t currTime = time(NULL);
    if (currTime - timeSinceEpoch >= 15780000)
        strftime(formattedTime, 15, "%b %d %Y", localtime(&timeSinceEpoch));
    else
        strftime(formattedTime, 15, "%b %d %H:%M", localtime(&timeSinceEpoch));

    printf("%s ", formattedTime);
    return 0;
}

int ls_processDir(char *path, int flagA, int flagL, int multipleDirs) {
    if (path == NULL) return 1;
    struct stat statBuff;
    if (lstat(path, &statBuff) == -1) {
        perror(path);
        return 1;
    }
    if (!S_ISDIR(statBuff.st_mode)) {
        if (flagL && ls_l_info(path)) return 1;
        printf("%s",path);
        printf("\n");
        return 0;
    }
    if (multipleDirs) {
        printf("%s:\n", path);
    }

    if (flagL && print_total(path, flagA)) return 1;
    DIR *fDir = opendir(path);
    if (fDir == NULL) {
        perror("ls");
        return 1;
    }
    struct dirent *entry = NULL;
    char *filePath = (char *) malloc(PATH_MAX);
    if (filePath == NULL) {
        perror("ls");
        return 1;
    }
    errno = 0;

    while ((entry = readdir(fDir))) {
        if (!flagA && entry->d_name[0] == '.') continue;
        sprintf(filePath, "%s/%s", path, entry->d_name);

        if (flagL && ls_l_info(filePath)) return 1;
        if (lstat(filePath, &statBuff) == -1) {
            perror(filePath);
            free(filePath);
            return 1;
        }
        if (S_ISDIR(statBuff.st_mode)) printf(BLUE "%s" RESET, entry->d_name);
        else if (S_ISLNK(statBuff.st_mode)) printf(GREEN "%s" RESET, entry->d_name);
        else printf(RESET "%s", entry->d_name);
        printf("\n");
    }
    if (errno != 0) {
        perror("ls");
        free(filePath);
        return 1;
    }
    if (multipleDirs) printf("\n");
    closedir(fDir);
    free(filePath);
    return 0;
}

int ls(vector *tokens) {
    optind = 0;
    int opt, flagL = 0, flagA = 0;
    while ((opt = getopt(tokens->size, tokens->arr, ":la")) != -1) {
        switch (opt) {
            case 'l':
                flagL = 1;
                break;
            case 'a':
                flagA = 1;
                break;
            default:
                fprintf(stderr, RED "ls: Invalid argument\n" RESET "Usage: ls -[al] ... [FILE]\n");
                return 1;
        }
    }

    int hasArgs = 0, statusCode = 0, multipleDirs = 0;
    if (optind < tokens->size - 1) {
        //print directory names as well before printing their contents
        multipleDirs = 1;
    }
    for (; optind < tokens->size; optind++) {
        hasArgs = 1;
        statusCode |= ls_processDir(tokens->arr[optind], flagA, flagL, multipleDirs);
    }
    if (!hasArgs) {
        statusCode |= ls_processDir(".", flagA, flagL, multipleDirs);
    }
    return statusCode;
}
