#include <stdio.h>
#include <sys/utsname.h>

int main() {
    struct utsname system_info;

    if (uname(&system_info) == -1) {	//현재 시스템의 정보를 반환하는 uname()함수
        perror("uname");
        return 1;
    }

    printf("%s %s %s %s %s %s %s GNU/%s\n", system_info.sysname, system_info.nodename, 
                                	system_info.release, system_info.version, 
                                	system_info.machine, system_info.machine,
					system_info.machine, system_info.sysname);
	//운영체제 이름, 네트워크 노드 이름, 커널 버전, 운영 체제 버전, 하드웨어 플랫폼 출력

    return 0;
}

