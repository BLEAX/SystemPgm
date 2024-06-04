#include <stdio.h>
#include <time.h>

int main() {
    time_t rawtime;                     // 시간을 초 단위로 저장하는 정수형 time_t 타입으로 변수 선언
    struct tm *timeinfo;                // 시간에 대한 정보를 가지고 있는 tm 구조체를 참조하는 포인터 변수
    char buffer[80];

    time(&rawtime);                     // 초 단위 시간 정보를 서버에서 받아오는 time() 함수
    timeinfo = gmtime(&rawtime);        // time()으로 받아온 초 단위 시간을 gmtime()으로 GMT(=UTC)시간으로 변환

    strftime(buffer, sizeof(buffer), "%a %b %e %T UTC %Y", timeinfo);
    // %a = 요일, %b = 월, %e = 일, %T = 시:분:초, %Z = (시간대)지역, %Y = 연도

    printf("%s\n", buffer);

    return 0;
}

