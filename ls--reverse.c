#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

// 함수 선언
void list_dir(const char *path);

int main(int argc, char *argv[]) {
    const char *dir;

    if (argc == 2) {
        dir = argv[1];
    } else {
        dir = ".";
    }

    list_dir(dir);

    return 0;
}

void list_dir(const char *path) {
    struct dirent **namelist;
    int n;

    // scandir를 사용하여 디렉토리 내용을 읽음
    n = scandir(path, &namelist, NULL, alphasort);
    if (n < 0) {
        perror("scandir");
        return;
    }

    // 내용을 역순으로 출력
    while (n--) {
        // "."와 ".." 디렉토리를 제외하고 출력
        if (strcmp(namelist[n]->d_name, ".") != 0 && strcmp(namelist[n]->d_name, "..") != 0) {
            printf("%s\t", namelist[n]->d_name);
        }
        free(namelist[n]);
    }
    printf("\n");
    free(namelist);
}

