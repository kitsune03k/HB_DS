#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node * next;
} Node;

int main(void)
{
	Node * head = NULL;    // NULL 포인터 초기화
	Node * tail = NULL;

    /*
    Node * DMY = (Node*)malloc(sizeof(Node));
    head = DMY;
    tail = DMY;

    이렇게 해도 상관은 없지만 DMY가 쓰레기값 출력함
    */

    head = (Node*)malloc(sizeof(Node));    // 추가 된 문장, 더미 노드 추가
    tail = head;

    int readData;
	Node * newNode = NULL;

	/**** 데이터를 입력 받는 과정 ****/
    while(1)
    {
        printf("input natural number: ");
        scanf("%d", &readData);
        if(readData < 1)
            break;

        /*** 노드의 추가과정 ***/
        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = readData;
        newNode->next = NULL;

        tail->next = newNode;
        tail = newNode;
    }
	printf("\n");

    Node * cur = NULL;
	/**** 입력 받은 데이터의 출력과정 ****/
	printf("showall! \n");
	if(head == NULL) 
	{
		printf("no saved natural number. \n");
	}
	else 
	{
		cur = head;
		printf("%d  ", cur->data);   // 첫 번째 데이터 출력
		// 첫 번째 DATA는 더미!! 가비지 값 출력됨!!

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

		printf("delete %d. \n", head->data);
		free(delNode);    // 첫 번째 노드의 삭제
		
		while(delNextNode != NULL)    // 두 번째 이후의 노드 삭제 위한 반복문
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("delete %d. \n", delNode->data);
			free(delNode);    // 두 번째 이후의 노드 삭제
		}
	}

	return 0;
}