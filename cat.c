#include <stdio.h>

/*텍스트 파일 내용을 표준출력에 프린트*/
int main(int argc, char *argv[]) {
	FILE *fp; 			//파일 포인터
	int c;				//문자를 저장할 변수 (EOF 판단을 위해 int)

	if (argc < 2) fp = stdin; 	//명령줄 인수가 2보다 적으면 표준입력 사용해서 읽기
	else fp = fopen(argv[1], "r"); 	//인수로 파일을 받으면 읽기모드로 파일 읽기

	c = getc(fp); 			//파일로부터 문자 읽기
	while(c != EOF) {		//파일 끝이 아니면
		putc(c, stdout);	//읽은 문자를 한 글자씩 표준출력에 출력
		c = getc(fp); 		//다음 문자 읽기
	}

	fclose(fp);			
	return 0;
}
