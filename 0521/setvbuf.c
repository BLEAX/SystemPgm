#include <stdio.h>
int main( void )
{
char buf[1024];
FILE *fp1, *fp2;
fp1 = fopen("data1", "a");
fp2 = fopen("data2", "w");
if( setvbuf(fp1, buf, _IOFBF, sizeof( buf ) ) != 0 )
printf("첫 번째 스트림: 잘못된 버퍼\n" );
else
printf("첫 번째 스트림: 1024 바이트 크기 버퍼 사용\n" );
if( setvbuf(fp2, NULL, _IONBF, 0 ) != 0 )
	printf("두 번째 스트림: 잘못된 버퍼\n" );
else
	printf("두 번째 스트림: 버퍼 미사용\n" );
}

