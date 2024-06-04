#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <seconds>\n", argv[0]);
        return 1;
    }

    int seconds = atoi(argv[1]);				//인수로 받아온 문자열을 atoi함수로 숫자로 변환
    char command[50];
    snprintf(command, sizeof(command), "sleep %d", seconds);	//snprintf()함수로 버퍼, 버퍼 크기, 
							    	//문자열을 받아와서 버퍼에 저장
    system(command);

    return 0;
}

