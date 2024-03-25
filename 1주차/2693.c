// n번째 큰 수
#include <stdio.h>

int main()
{
    int tc;
    scanf("%d", &tc);                  // 테스트 케이스 개수 입력받기
    int maxNum[3], num;                // maxNum에 입력 받은 수 중 가장 큰 3개의 수를 오름차순으로 저장. num은 입력 받기용 변수
    for (int i=0; i<tc; i++){
        maxNum[0]=0; maxNum[1]=0; maxNum[2]=0;
        for (int j=0; j<10; j++){      // 10개의 수를 입력 받으며 비교할 것임
            scanf("%d", &num);         // num에 임시로 숫자를 저장
            for (int k=0; k<3; k++){
                if (maxNum[k]<num){    // 이때까지 입력 받은 수 중에서 1,2,3 순위 안에 들면 해당 자리에 저장. 그러지 않으면 배열에 저장하지 않음
                    for (int l=2; l>k; l--)
                        maxNum[l] = maxNum[l-1];
                    maxNum[k]=num;
                    break;
                }
            }
        }
        printf("%d\n", maxNum[2]);  // 3번째로 큰 수를 출력함.
    }

    return 0;
}
