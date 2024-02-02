#ifndef __DBD_LINKED_LIST_H__
#define __DBD_LINKED_LIST_H__

#define TRUE	1
#define FALSE	0

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node * next;
	struct _node * prev;
} Node;

typedef struct _dbDLinkedList
{
	Node * head;
	Node * tail;
	Node * cur;
	int numOfData;
} DBDLinkedList;

typedef DBDLinkedList List;

void ListInit(List * plist);
void LInsertTail(List * plist, Data data); // 꼬리에 노드를 추가한다.
void LInsertHead(List * plist, Data data); // 머리에 노드를 추가한다.

int LFirst(List * plist, Data * pdata);
int LLast(List * plist, Data * pdata);

int LNext(List * plist, Data * pdata);
int LPrev(List * plist, Data * pdata);

Data LRemove(List * plist);
int LCount(List * plist);

#endif