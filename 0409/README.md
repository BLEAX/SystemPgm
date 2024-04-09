**유닉스에서 파일**

- **연속된 바이트의 나열**
- **특별한 다른 포맷을 정하지 않음**
- **디스크 파일뿐만 아니라 외부 장치에 대한 인터페이스**


**파일 열기 : open()**

- 파일을 사용하기 위해서는 먼저 open() 시스템 호출을 이용하여 파일을 열어야 한다.

```c
**#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int open (const char *path, int oflag, [ mode_t mode ]);**

파일 열기에 성공하면 파일 디스크립터를, 실패하면 -1을 리턴
```


**파일 생성 : creat()**

- creat() 시스템 호출 :
    - **path 가 나타내는 파일을 생성하고 쓰기 전용으로 연다.**
    - **생성된 파일의 사용권한은 mode 로 정한다.**
    - **기존 파일이 있는 경우에는 그 내용을 삭제하고 연다.**

```
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int creat(const char *path, mode_t mode );
//open(path, WRONLY | O_CREAT | O_TRUNC, mode); 시스템 호출과 동일

파일 생성에 성공하면 파일 디스크립터를, 실패하면 1 을 리턴
```


**파일 닫기 : close()**

- **close() 시스템 호출은 fd 가 나타내는 파일을 닫는다**.

```
#include <unistd.h>
int close( int fd );

fd가 나타내는 파일을 닫는다 .
성공하면 0, 실패하면 1을 리턴한다 .
```


**데이터 읽기 : read()**

- read() 시스템 호출 :
    - **fd가 나타내는 파일에서 nbytes만큼의 데이터를 읽고 읽은 데이터는 buf에 저장한다.**

```c
#include <unistd.h>
ssize_t read ( int fd , void *buf , size_t nbytes );

//모든 자료형을 받기 위해 buf를 void *으로 사용.

//**fd = open의 리턴이 int이기 때문에 int형
ex)
if ((fd = open(argv[1], O_RDONLY)) == -1) perror(argv[1]);
//파일 열기에 실패할 경우, error를 프린트(perror)**

파일 읽기에 성공하면 읽은 바이트 수, 파일 끝을 만나면 0,
실패하면 -1을 리턴
```


**데이터 쓰기 : write()**

- write() 시스템 호출 :
    - **buf에 있는 nbytes 만큼의 데이터를 fd가 나타내는 파일에 쓴다.**


# 파일 디스크립터
```
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	int fd1, fd2;
	
	if((fd1 = creat myfile ", 0600)) == 1)
	perror("myfile");
	
	write(fd1, "Hello! Linux", 12); //C는 문자열 끝에 null이 들어가 있음
	fd2 = dup(fd1);

	write(fd2, "Bye! Linux", 10);
	exit(0);
}
```


**파일 위치 포인터** 

- 파일 위치 포인터는 파일 내에 읽거나 쓸 위치인 현재 파일 위치(current file position)를
가리킨다.

**파일 위치 포인터 이동**

**lseek() 시스템 호출**

- **임의의 위치로 파일 위치 포인터를 이동시킬 수 있다.**

```c
#include <unistd.h>
off_t lseek(int fd, off_t offset, int whence);
이동에 성공하면 현재 위치를 리턴하고 실패하면 -1을 리턴한다.
```


ex)

**파일 위치 이동**
```
lseek(fd, 0L, SEEK_SET); // 파일 시작으로 이동(rewind). 0L은 Long형으로 캐스팅 한것
lseek(fd, 100L, SEEK_SET); // 파일 시작에서 100바이트 위치로
lseek(fd, 0L, SEEK)END); // 파일 끝으로 이동(append)
```

**레코드 단위로 이동** ( bit < nibble < byte < word < field < **record(서로 연관있는 데이터들을 묶어 놓은 것)** < table < DB )
```
lseek(fd, n * sizeof(record), SEEK_SET); // n+1번째 레코드 시작위치로
lseek(fd, sizeof(record), SEEK_CUR); // 다음 레코드 시작위치로
lseek(fd, -sizeof(record), SEEK_CUR); // 전 레코드 시작위치로
```

**파일 끝 이후로 이동**
```
lseek(fd, sizeof(record), SEEK_END); //파일 끝에서 한 레코드 다음 위치로
```






**Don't reinvent the wheel**


**argc** : 

**argv** :


**size_t** : 

**ssize_t** : 

**파일 디스크립터** : 
