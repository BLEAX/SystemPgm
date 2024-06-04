#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    DIR *dir;
    struct dirent *entry;

    // 디렉터리 경로 설정 (인자가 없을 경우 현재 디렉터리)
    char *path = (argc < 2) ? "." : argv[1];

    // 디렉터리 열기
    dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    // 디렉터리의 각 항목을 읽어 출력
    while ((entry = readdir(dir)) != NULL) {
        // .과 ..은 생략하지 않으려면 주석 해제
        // if (entry->d_name[0] != '.') {
        printf("%s\n", entry->d_name);
        // }
    }

    // 디렉터리 닫기
    closedir(dir);
    return 0;
}

