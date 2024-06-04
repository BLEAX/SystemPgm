#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void listDirectory(const char *path) {
    struct dirent *entry;
    DIR *dp = opendir(path);

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        // Skip . and ..
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            printf("%s\t", entry->d_name);
        }
    }

    printf("\n");
    closedir(dp);
}

int main(int argc, char *argv[]) {
    const char *path;

    if (argc > 1) {
        path = argv[1];
    } else {
        path = ".";
    }

    listDirectory(path);

    return 0;
}

