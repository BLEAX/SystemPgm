#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int c;
    int lineNumber = 1; // 줄 번호 초기화

    if (argc < 2) fp = stdin;
    else fp = fopen(argv[1], "r");

    printf("%6d  ", lineNumber++);		//첫 번째 줄 번호 출력

    while ((c = getc(fp)) != EOF) {
        putc(c, stdout);
        if (c == '\n') {
            if ((c = getc(fp)) != EOF) {	//다음 줄 번호 출력
                printf("%6d  ", lineNumber++);
                putc(c, stdout);
            }
        }
    }

    fclose(fp);
    return 0;
}

