#include <stdio.h>

void clear_screen() {
    printf("\033[2J\033[H"); // ANSI 이스케이프 시퀀스를 통해 화면을 지웁니다.
}

int main() {
    clear_screen(); // 화면을 지우는 함수를 호출합니다.
    return 0;
}

