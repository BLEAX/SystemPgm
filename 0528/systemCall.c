#include <sys/wait.h>
#include <stdio.h>
int main()
{
int status;
if ((status = system("date")) < 0)
perror("mysystem() 오류");
printf("종료코드 %d\n", WEXITSTATUS(status));
if ((status = system("hello")) < 0)
perror("mysystem() 오류");
printf("종료코드 %d\n", WEXITSTATUS(status));
if ((status = system("who; exit 44")) < 0)
perror("mysystem() 오류");
printf("종료코드 %d\n", WEXITSTATUS(status));
}
