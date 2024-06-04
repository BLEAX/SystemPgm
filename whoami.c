#include <stdio.h>
#include <stdlib.h>

int main() {
    char *username = getenv("USER");	//환경변수 USER를 username으로 저장
    if (username == NULL) {
        perror("getenv");
        return 1;
    }
    
    printf("%s\n", username);
    return 0;
}

