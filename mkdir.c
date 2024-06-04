#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    if (mkdir(argv[1], 0755) == -1) {		//권한 모드 0755로 디렉토리 생성 (rwxr-xr-x)
        perror("mkdir");
        return 1;
    }

    return 0;
}

