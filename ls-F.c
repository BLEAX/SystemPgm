#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

// 파일 이름 뒤에 특수 기호를 추가하여 출력하는 함수
void printFileNameWithSpecialChar(struct dirent *entry, struct stat fileInfo) {
    if (S_ISDIR(fileInfo.st_mode)) {
        printf("%s/\n", entry->d_name); // 디렉토리일 경우 '/' 추가
    } else if (fileInfo.st_mode & S_IXUSR || fileInfo.st_mode & S_IXGRP || fileInfo.st_mode & S_IXOTH) {
        printf("%s*\n", entry->d_name); // 실행 파일일 경우 '*' 추가
    } else {
        printf("%s\n", entry->d_name);
    }
}

int main() {
    DIR *directory;
    struct dirent *entry;
    struct stat fileInfo;

    // 현재 디렉토리 열기
    directory = opendir(".");
    if (directory == NULL) {
        perror("Unable to open directory");
        return 1;
    }

    // 디렉토리 내의 각 파일 및 디렉토리에 대한 정보 출력
    while ((entry = readdir(directory)) != NULL) {
        if (stat(entry->d_name, &fileInfo) == -1) {
            perror("Unable to get file status");
            return 1;
        }
        printFileNameWithSpecialChar(entry, fileInfo);
    }

    // 디렉토리 닫기
    closedir(directory);

    return 0;
}

