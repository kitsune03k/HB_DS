#include <stdio.h>
#include <stdlib.h>
#include "DBDLinkedList.h"

void ListInit(List * plist)
{
	Node * dmyhead = (Node*)malloc(sizeof(Node)); // head 더미노드 생성
	Node * dmytail = (Node*)malloc(sizeof(Node)); // tail 더미노드 생성

	// plist의 head, tail 지정
	plist->head = dmyhead;
	plist->tail = dmytail;

	// 이들은 불변
	plist->head->prev = NULL;
	plist->tail->next = NULL;

	// head, tail 서로 이어줌
	plist->head->next = plist->tail;
	plist->tail->prev = plist->head;

	plist->numOfData = 0;
}

void LInsertTail(List * plist, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->tail;
	newNode->prev = plist->tail->prev;

	plist->tail->prev->next = newNode; // tail(dmy) 이전 node -> next는 newNode를 가리켜야함
	plist->tail->prev = newNode; // tail(dmy) -> prev는 newNode를 가리켜야함

	(plist->numOfData)++;
}

void LInsertHead(List * plist, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->prev = plist->head;
	newNode->next = plist->head->next;

	plist->head->next->prev = newNode; // head(dmy) 이후 node -> prev는 newNode를 가리켜야함
	plist->head->next = newNode; // head(dmy) -> next는 newNode를 가리켜야함

	(plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata)
{
	plist->cur = plist->head->next; // head는 dmy
	*pdata = plist->cur->data; 

	return TRUE;
}

int LLast(List * plist, Data * pdata)
{
	plist->cur = plist->tail->prev; // tail은 dmy
	*pdata = plist->cur->data;

	return TRUE;
}

int LNext(List * plist, Data * pdata)
{
	if(plist->cur->next == plist->tail)
		return FALSE;

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;

	return TRUE;
}

int LPrev(List * plist, Data * pdata)
{
	if(plist->cur->prev == plist->head)
		return FALSE;

	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;

	return TRUE;
}

Data LRemove(List * plist)
{
	Node * rpos = plist->cur; // LFirst, LLast, LNext, LPrev로 커서가 옮겨졌음이 보장됨
	Data rdata = rpos->data;

	rpos->prev->next = rpos->next;
	rpos->next->prev = rpos->prev;
	plist->cur = rpos->prev;
	
	free(rpos);
	(plist->numOfData)--;

	return rdata;
}

int LCount(List * plist)
{
	return plist->numOfData;
}