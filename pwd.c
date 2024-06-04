#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main() {
    char cwd[PATH_MAX];

    if (getcwd(cwd, sizeof(cwd)) != NULL) {	//현재 작업 디렉토리를 받아오는 getcwd()함수
        printf("%s\n", cwd);
    } else {
        perror("getcwd");
        return 1;
    }

    return 0;
}
 
