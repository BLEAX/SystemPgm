#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <fcntl.h> 
#include "student.h" 
#define START_ID 1201001 
/* 잠금을 이용한 학생데이터베이스 수정프로그램*/ 
int main(int argc, char* argv[]) { 
	int fd, id; 
	struct student record; 

	if (argc < 2) { 
		fprintf(stderr,  "사용법: %sfile\n", argv[0]); 
		exit(1); 
	} 

	if ((fd= open(argv[1], O_RDWR)) == -1) { 
		perror(argv[1]); 
		exit(2); 
	} 

	printf("\n수정할 학생의 학번 입력:"); 
	while (scanf("%d", &id) == 1) { 
		lseek(fd,  (long) (id-START_ID)*sizeof(record), SEEK_SET); 
		if (lockf(fd, F_LOCK, sizeof(record)) == -1) {  /* 쓰기 잠금*/ 
			perror(argv[1]); 
			exit(3); 
		} 

		if ((read(fd, (char *) &record, sizeof(record)) > 0) && 
			(record.id != 0)) 
			printf("이름:%s\t 학번:%d\t 점수:%d\n", 
				record.name, record.id, record.score); 
		else printf("레코드%d 없음\n", id); 
		
		printf("새로운 점수: "); 
		scanf("%d", &record.score); 
		lseek(fd, (long) -sizeof(record), SEEK_CUR); 
		write(fd, (char *) &record, sizeof(record)); 

		lseek(fd,  (long) (id-START_ID)*sizeof(record), SEEK_SET);
		lockf(fd, F_ULOCK, sizeof(record));  /* 잠금 해제*/ 
		printf("\n수정할 학생의 학번 입력:");
	} 
	close(fd); 
	exit(0); 
}
