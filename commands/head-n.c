#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <num_lines> <file>\n", argv[0]);	//에러 출력, 사용법 출력
        return 1;
    }

    int num_lines = atoi(argv[1]); //두 번째로 받은 인자를 정수로 변환
    if (num_lines <= 0) {	   //출력할 라인의 수가 0보다 작으면 에러출력
        fprintf(stderr, "Number of lines must be a positive integer\n");
        return 1;
    }

    FILE *file = fopen(argv[2], "r"); //파일을 읽기 전용으로 열어서 파일 포인터 변수에 저장
    if (file == NULL) {	 //파일 포인터 변수가 비어있으면
        perror("fopen"); //에러 출력
        return 1;
    }

    char line[MAX_LINE_LENGTH]; //1024개의 문자를 저장할 수 있는 배열 선언
    for (int i = 0; i < num_lines && fgets(line, sizeof(line), file) != NULL; i++) {
        printf("%s", line);
    }

    fclose(file);
    return 0;
}

