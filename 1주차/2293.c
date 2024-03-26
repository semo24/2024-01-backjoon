#include <stdio.h>
int main()
{
    int coinType, targetMoney, coin[100], count[10000];    //코인 종류 개수, 목표금, 각 코인의 값어치 저장, 한 코인 종류에서 1부터 목표금까지의 경우의 수 저잦
    scanf("%d %d", &coinType, &targetMoney);
    for (int i=0; i<coinType; i++){
        scanf("%d", &coin[i]);
    }
    int n=coin[0]-1;
    for (int i=0; i<targetMoney; i++){                    // 맨 처음 동전의 경우의 수
        if (n == i) {
            count[i] = 1;
            n += coin[0];
        }
        else count[i] = 0;
    }
    for (int i=1; i<coinType; i++){
        if (coin[i] <= targetMoney){                  // 두 번째 동전부터 자신의 값어치-1에 1 더하기
            count[coin[i]-1]++;                       // 이전 동전의 같은 금액의 경우의 수 + 지금 동전의 금액-지금동전값어치 = 지금동전의 지금동전 값어치
            for (int j=coin[i]; j<targetMoney; j++){
                count[j] += count[j-coin[i]];
            }
        }
    }
    printf("%d", count[targetMoney-1]);
    return 0;
}
