return 0 : 성공(success)을 반환
0을 제외한 모든 숫자는 에러


**option** : 
ls의 옵션 : long option과 short option으로 나눌 수 있음. (하는 동작은 같음.) 
    -a 또는 --all : (all, 모두 출력) 
    등등 대부분의 옵션은 long option과 short option 둘 다 가지고 있음.
    예외) -l : (list, 리스트 출력)은 long option이 없음.


ls 구현 시 all을 주고 싶을 시 : 
  -a의 경우에는 히든 파일까지 출력
  -l의 경우에는 long으로 출력


ls -l / 이나 ls / -l 은 순서는 다르지만 모두 같은 동작을 함.


ls 명령 구현시 : short option과 long option을 구현하면 점수가 높아짐.
1. ls구현 시 1점
2. -l구현 시 1점
3. /구현 시 1점
4. --all 구현 시 1점 등등


