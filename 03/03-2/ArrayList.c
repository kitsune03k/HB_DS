#include <stdio.h>
#include "ArrayList.h"

void ListInit(List * plist)
{
	(plist->numOfData) = 0; // 초기화시 원소갯수 0개
	(plist->curPosition) = -1; // 초기화시 커서위치 -1
}

void LInsert(List * plist, LData data)
{
	if(plist->numOfData > LIST_LEN)  // 원소갯수가 100(배열최대길이)보다 클때
	{
		puts("저장이 불가능합니다.");
		return;
	}

	plist->arr[plist->numOfData] = data; // ex) 원소 3개일때, 다음 저장 arr[3](네번째)에
	(plist->numOfData)++; // 저장하고 원소갯수++
}

int LFirst(List * plist, LData * pdata)
{
	if(plist->numOfData == 0) // 원소갯수 0개일때
		return FALSE; // 0 반환

	(plist->curPosition) = 0; // 커서위치 = 0
	*pdata = plist->arr[0]; // *pdata의 값은 arr[0]과 같음 (포인터로 직접 접근)
	return TRUE; // 1 반환
}

int LNext(List * plist, LData * pdata)
{
	if(plist->curPosition >= (plist->numOfData)-1) // 커서위치가 인덱스보다 크거나 같을경우
		return FALSE; // 0 반환

	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE; // 1 반환
}

LData LRemove(List * plist) // Ldata는 int
{
	int rpos = plist->curPosition; // 커서위치 (=배열 인덱스)
	int num = plist->numOfData; // 원소갯수
	int i;
	LData rdata = plist->arr[rpos]; // int rdata = arr[커서위치]

	for(i=rpos; i<num-1; i++) // 삭제할 요소부터 원소갯수(인덱스+1)-1까지
		plist->arr[i] = plist->arr[i+1]; // 배열 다음의 값을 덮어씌움

	(plist->numOfData)--; // 삭제했으니 원소갯수 --
	(plist->curPosition)--; // 커서위치 --
	return rdata; //
}