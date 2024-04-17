#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <utime.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	struct stat buf;
	struct utimbuf time;

	if (argc < 3) {
		fprintf(stderr, "사용법 : cptime file1 file2\n");
		exit(1);
	}
	
	if (stat(argv[1], &buf) < 0) { // 상태 가져오기
		perror("stat()");
		exit(-1);
	}

	time.actime = buf.st_atime;
	time.modtime = buf.st_mtime;

	if (utime(argv[2], &time)) // 접근, 수정 시간 복사
		perror("utime");
	else exit(0);
}

