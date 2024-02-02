#ifndef __C_LINKED_LIST_H__
#define __C_LINKED_LIST_H__

#define TRUE	1
#define FALSE	0

typedef struct _employee
{
	char name[24];
	int id;
    int age;
} Employee;

typedef Employee Data;

typedef struct _node
{
	Data data;
	struct _node * next;
} Node;

typedef struct _CLL
{
	Node * tail;
	Node * cur;
	Node * before;
	int numOfData;
} List;

void ListInit(List * plist);
void LInsert(List * plist, Data data); // 뒤에 추가 - tail 됨
void LInsertFront(List * plist, Data data); // 앞에 추가 - tail->next 됨

int LFirst(List * plist, Data * pdata);
int LNext(List * plist, Data * pdata);
Data LRemove(List * plist);
int LCount(List * plist);

#endif