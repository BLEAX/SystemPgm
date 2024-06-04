#include <stdio.h>
#include <stdlib.h>
#define DEFAULT_NUM_LINES 10
#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    char *file_name = argv[1];			//인수로 받은 프로그램의 위치를 file_name에 저장
    FILE *file = fopen(file_name, "r"); 	//읽기 전용 모드로 파일을 열어서 저장
    
    if (file == NULL) {
        perror("fopen");
        return 1;
    }

    char line[MAX_LINE_LENGTH];			//최대 1024개의 라인

    for (int i = 0; i < DEFAULT_NUM_LINES && fgets(line, sizeof(line), file) != NULL; i++) {
        printf("%s", line);		//10줄 이하이고 fgets로 받아온 라인이 NULL이 아니면 
					//한 줄 씩 출력
    }


    fclose(file);
    return 0;
}

