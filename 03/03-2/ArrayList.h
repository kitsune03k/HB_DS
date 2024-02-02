#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#include "NameCard.h"

#define TRUE	1
#define FALSE	0

/*** ArrayList의 정의 ****/
#define LIST_LEN	100
typedef NameCard * LData;

typedef struct
{
	LData arr[LIST_LEN]; // 실질적으로 NameCard * 저장될 list, 크기 sizeof(ptr)*100
	int numOfData; // 원소 갯수
	int curPosition; // 커서 위치
} List;


/*** ArrayList와 관련된 연산들 ****/

void ListInit(List * plist);
void LInsert(List * plist, LData data);

int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);

LData LRemove(List * plist);

#endif