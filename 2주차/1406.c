// 에디터

#include <stdio.h>
#include <string.h>
int main()
{
    int m, i = 1;
    char abc[600000];    // 커서를 기준으로 왼쪽에 있는 문자열을 저장
    char def[600000];    // 커서를 기준으로 오른쪽에 있는 문자열을 저장
    char command;        // 명령어
    scanf("%[^\n]s", abc);  // 초기 문자열
    scanf("%d", &m);        // 명령어 개수
    int cursor = strlen(abc);  // 초기 커서 위치
    int rightCursor = 0;        // def[0]부터 def[rightCursor-1]까지 문자열이 커서 오른쪽 문자열. (거꾸로 저장됨)
    for (i=0; i<m; i++){
        scanf(" %c", &command);
        switch (command)
        {
        case 'P':
            scanf(" %c", &command);      // 커서 왼쪽 문자 입력
            abc[cursor++] = command;
            break;
        case 'L' :                       // 커서 왼쪽으로 이동
            if (cursor){
                def[rightCursor++] = abc[--cursor];
            }
            break;
        case 'D' :                      // 커서 오른쪽으로 이동
            if (rightCursor){
                abc[cursor++] = def[--rightCursor];
            }
            break;
        case 'B' :                      // 커서 왼쪽 문자 삭제
            if (cursor){
                cursor--;
            }
        }
    }
    for (i=0; i<cursor; i++){
        printf("%c", abc[i]);
    }
    for (i=rightCursor-1; i>=0; i--){
        printf("%c", def[i]);
    }
    return 0;
}
