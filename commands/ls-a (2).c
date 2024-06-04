#include <stdio.h>
#include <dirent.h>

int main() {
    DIR *directory;
    struct dirent *entry;

    // 현재 디렉토리 열기
    directory = opendir(".");
    if (directory == NULL) {
        perror("Unable to open directory");
        return 1;
    }

    // 디렉토리 내의 각 파일 및 디렉토리 출력
    while ((entry = readdir(directory)) != NULL) {
        printf("%s\t", entry->d_name);
    }

    printf("\n");

    // 디렉토리 닫기
    closedir(directory);

    return 0;
}

