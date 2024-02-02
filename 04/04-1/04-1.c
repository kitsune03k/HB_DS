#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    struct _node * next;
	int data;
} Node;

int main(void)
{
	Node * head = NULL;    // NULL 포인터 초기화
	Node * tail = NULL;

    int readData;
	Node * newNode = NULL;

	/**** 데이터를 입력 받는 과정 ****/
	while(1)
	{
		printf("자연수 입력: ");
		scanf("%d", &readData);
		if(readData < 1){
            break;
        }

        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = readData;
        newNode->next = NULL;

        if(head == NULL){ // 첫 노드 생성시에
            tail = newNode;
            head = newNode; // 역순이기에 새 노드는 무조건 head가 됨
        }
        else { // 두번째 이후 노드 생성시에
            newNode->next = head; // 안바뀐 head 노드 쓰고
            head = newNode; // 역순이기에 새 노드는 무조건 head가 됨, head 바꿔줌
        }
    }
	printf("\n");

    Node * cur = NULL;
	/**** 입력 받은 데이터의 출력과정 ****/
	printf("입력 받은 데이터의 전체출력! \n");
	if(head == NULL) 
	{
		printf("저장된 자연수가 존재하지 않습니다. \n");
	}
	else 
	{
		cur = head; 
		printf("%d  ", cur->data);   // 첫 번째 데이터 출력
		
		while(cur->next != NULL)    // 두 번째 이후의 데이터 출력
		{
			cur = cur->next;
			printf("%d  ", cur->data);
		}
	}
	printf("\n\n");

	/**** 메모리의 해제과정 ****/
	if(head == NULL) 
	{
		return 0;    // 해제할 노드가 존재하지 않는다.
	}
	else 
	{
		Node * delNode = head;
		Node * delNextNode = head->next;

		printf("%d을(를) 삭제합니다. \n", head->data);
		free(delNode);    // 첫 번째 노드의 삭제
		
		while(delNextNode != NULL)    // 두 번째 이후의 노드 삭제 위한 반복문
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d을(를) 삭제합니다. \n", delNode->data);
			free(delNode);    // 두 번째 이후의 노드 삭제
		}
	}

	return 0;
}