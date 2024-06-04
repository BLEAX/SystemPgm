#include <stdio.h>

int main(int argc, char *argv[]) {
    // 명령줄 인수에 문자열이 있을 경우 해당 문자열을 출력
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            printf("%s", argv[i]);
            // 공백을 출력하여 인수를 구분
            if (i < argc - 1) {
                printf(" ");
            }
        }
    } else {
        // 인수가 없을 경우 개행만 출력
        printf("\n");
    }

    return 0;
}
