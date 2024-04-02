**Makefile**

- 소프트웨어 빌드 자동화를 위한 도구
    - 대상List : 의존성List
    - [tab]      : 명령List

**대상(target)**

- Make명령어가 궁극적으로 생성하는 것
- 명령이 수행되어 나온 결과 파일 지정

**의존성(dependency)**

- 대상과 대상을 생성하는데 필요한 소스

기본 명령어

make: Makefile을 실행 → 프로젝트 빌드

make clean: 생성된 파일 정리

변수와 매크로 활용

$@ : 현재의 목표 파일 이름

$* : 확장자가 없는 현재의 목표 파일 이름

$< : 현재 목표 파일보다 최근에 갱신된 파일


시스템 콜
    파일 열기
        O_RDONLY : 읽기 모드, read() 호출은 사용 가능
        O_WRONLY : 쓰기 모드, write() 호출은 사용 가능
        O_RDWR : 읽기/쓰기 모드, read(), write() 호출 사용 가능
        O_APPEND : 데이터를 쓰면 파일 끝에 첨부된다.
        O_CREAT : 해당 파일이 없는 경우에 생성하며 mode는 생성할 파일의 사용권한을 나타낸다.
        O_TRUNC : 파일이 이미 있는 경우 내용을 지운다.
        O_EXCL : O_CREAT와 함께 사용되며 해당 파일이 이미 있으면 오류
        O_NONBLOCK :넌블로킹 모드로 입출력 하도록 한다.
        O_SYNC : write() 시스템 호출을 하면 디스크에 물리적으로 쓴 후 반환된다.

        
ex) fd = open("account", O_RDONLY);
    fd = open(argv[1], O_RDWR);
    fd = open(
