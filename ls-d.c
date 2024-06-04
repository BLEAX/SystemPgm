#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void print_directory_info(const char *path) {
    struct stat st;

    // 디렉터리 정보 얻기
    if (stat(path, &st) == -1) {
        perror("stat");
        return;
    }

    // 디렉터리인지 검사하고 출력
    if (S_ISDIR(st.st_mode)) {
        printf("%s\n", path);
    } else {
        fprintf(stderr, "%s is not a directory\n", path);
    }
}

int main(int argc, char *argv[]) {
    // 경로를 지정하지 않으면 현재 디렉터리 사용
    if (argc < 2) {
        print_directory_info(".");
    } else {
        for (int i = 1; i < argc; i++) {
            print_directory_info(argv[i]);
        }
    }

    return 0;
}

