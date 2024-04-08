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
