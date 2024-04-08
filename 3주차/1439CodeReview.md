# 뒤집기
### 문제 설명
0과 1로 이루어진 문자열 S를 연속적인 문자열 일부에서 0 혹은 1을 반대로 바꾸는 작업을 해 하나의 연속된 문자열로 만드는 최소 횟수.

### 풀이
문자열에서 같은 문자가 연속해 있을시 하나의 단어로 본다.
0단어, 1단어의 개수를 센다.
두 종류의 단어 중 더 적은 단어의 개수를 출력한다.

### 코드
```c
#include <stdio.h>
int main()
{
    int i=0, zeroOrOneWord[2]={0,0};   // 0과 1 연속된 단어 개수 저장
    char string01[1000000];
    scanf(" %s", string01);
    zeroOrOneWord[string01[0]-48]++;  // 첫번째 숫자의 단어 종류 +1
    while((string01[++i]) != '\0'){
        if (string01[i] != string01[i-1]) zeroOrOneWord[string01[i]-48]++;  // 같은 문제가 연속 될 시 단어 개수 +1
    }
    zeroOrOneWord[0]>zeroOrOneWord[1] ? printf("%d", zeroOrOneWord[1]) : printf("%d", zeroOrOneWord[0]);  // 더 적은 단어 개수 출력

    return 0;
}
```
  
### 코드 리뷰
```c
zeroOrOneWord[string01[0]-48]++;  // 첫번째 숫자의 단어 종류 +1
```
문자열의 첫 문자는 무조건 새로운 단어의 시작이기 때문에 해당 문자의 단어 개수를 1 늘린다.  
```c
if (string01[i] != string01[i-1]) zeroOrOneWord[string01[i]-48]++;  // 같은 문제가 연속 될 시 단어 개수 +1
```
이전의 문자와 다른 문자가 온다는 것은 새로운 단어의 시작이기 때문에 해당 문자의 단어 개수를 1 늘린다.
