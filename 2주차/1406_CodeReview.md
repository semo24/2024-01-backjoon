# 백준 1406 에디터
에디터에 저장되어있는 초기 문자열과 명령어를 입력받아 최종 문자열을 출력한다.
명령어
- L 커서 왼쪽으로 이동
- D 커서 오른쪽으로 이동
- B 커서 왼쪽 문자 삭제
- P x 커서 왼쪽에 문자 x 삽입
(커서 초기 위치는 문자열 끝)

### 풀이 방법
하나의 배열로 문자열을 저장하면 문자 하나를 수정하면 문자열 전체를 수정해야할 경우도 있을 수 있음.  
&rarr; 커서 왼쪽과 오른쪽의 문자열을 따로 저장  

+ 커서 이동 : cursor(왼쪽 문자열 끝)와 rightCursor(오른쪽 문자열 시작)의 위치 변경  
  - 왼쪽으로 이동 : 왼쪽 문자열의 문자 하나를 오른쪽 문자열에 저장
  - 오른쪽으로 이동 : 오른쪽 문자 하나를 왼쪽 문자열에 저장
+ 문자 삭제 : cursor 왼쪽으로 한 칸 이동
+ 문자 삽입 : cursor 자리에 문자 하나 삽입. cursor는 오른쪽으로 한 칸 이동

### 코드
```c
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
```
### 코드 설명
cursor 전 마지막 문자 표시 *
초기 문자열 
```c
[a,b,c,d,e*]   //왼쪽 문자열, 커서 5
[]             //오른쪽 문자열(쓰레기값 무시), 커서 0
```
L 입력 : 커서 왼쪽 이동
```c
[a,b,c,d*,e]   //왼쪽 문자열, 커서 4
[e*]           //오른쪽 문자열, 커서 1
```
P x 입력 : 커서 왼쪽에 x 삽입
```c
[a,b,c,d,x*]   //왼쪽 문자열, 커서 5
[e*]           //오른쪽 문자열, 커서 1
```
B 입력 : 커서 왼쪽 문자 삭제
```c
[a,b,c,d*,x]   //왼쪽 문자열, 커서 4
[e*]           //오른쪽 문자열, 커서 1
```
D 입력 : 커서 오른쪽으로 이동
```c
[a,b,c,d,e*]   //왼쪽 문자열, 커서 5
[]           //오른쪽 문자열, 커서 0
```   
  
  
   
  
출력
```
왼쪽 문자열 [a,b,c] 이고 오른쪽 문자열 [d,e,f]
cursor = 2, righCursor = 3
```
```c
abfed
// cursor와 righCursor 이상 위치에 저장되는 문자는 모두 무시. 오른쪽 문자열은 역순으로 저장.
```

## 실패 - 시간 초과
연결리스트를 사용하려했으나 시간 초과됨. (시간 제한 0.3)

### 코드 
```c
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    char data;
    struct node* next;
} node;

int main()
{
    int m, i, cusor=1;
    char abc[100000];
    char command;
    scanf("%[^\n]s", abc);
    scanf("%d", &m);
    node *head = (node*)malloc(sizeof(node));
    node *newNode = (node*)malloc(sizeof(node));
    node *preNode = (node*)malloc(sizeof(node));
    if (abc[0]=='\0') {
        head->next = NULL;
        preNode = head;
        cusor = 0;
    }
    else {
        newNode->data = abc[0];
        head->next = newNode;
        newNode->next = NULL;
        preNode = newNode;
    }
    while (abc[cusor] != '\0')
    {
        node *nextNode = (node*)malloc(sizeof(node));
        nextNode->data = abc[cusor++];
        nextNode->next = NULL;
        preNode->next = nextNode;
        preNode = nextNode;
    }
    int last = cusor;
    node *some;
    for (i=0; i<m; i++){
        scanf(" %c", &command);
        switch (command)
        {
        case 'P':
            scanf(" %c", &command);
            some = head;
            for (int j=0; j<cusor; j++){
                some = some->next;
            }
            node *lastNode = (node*)malloc(sizeof(node));
            lastNode->data = command;
            lastNode->next = some->next;
            some->next = lastNode;
            cusor++; last++;
            break;
        case 'L' :
            if (cusor) cusor--;
            break;
        case 'D' :
            if (last-cusor) cusor++;
            break;
        case 'B' :
            if (cusor){
                some = head;
                for (int j=0; j<cusor-1; j++){
                    some = some->next;
                }
                some->next = some->next->next;
                cusor--; last--;
            }
        }
        
    }
    some = head->next;
	while(some != NULL)
	{
		printf("%c",some->data);
		some = some->next;
	}
    return 0;
}
```
문자열을 다 입력받은 후 다시 연결리스트에 저장한 이유
* ```scanf```로 문자를 하나씩 입력받을경우 엔터를 입력받지 않아 ```abc[i]=='\n'``` 등의 방법으로 입력 멈추기를 못함.  
&rarr; 지금 생각해보니 숫자를 입력하면 입력을 멈췄으면 됐을 것 같다.
