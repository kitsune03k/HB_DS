#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"
#include "Point.h"

int PointComp(Point * pos1, Point * pos2)
{
	int retval = -1;
	
	// xpos 만족시
	if(pos1->xpos < pos2->xpos){
		// xpos와 ypos 모두 만족시
		if(pos1->ypos < pos2->ypos){
			return 0;
		}
		// xpos 만족하지만 ypos 불만족시
		else{
			return 1;
		}
	}
	// xpos 불만족시 : 무조건 진행
	else{
		return 1;
	}

	return retval;
}

int main(void)
{
	// list1은 L(Left)Insert, list2는 S(Sorted)Insert
	List list1, list2;
	Point compPos;
	Point * ppos;

	ListInit(&list1);
	ListInit(&list2);
	
	// SInsert할 list2만 SortRule 지정
	SetSortRule(&list2, PointComp);

	/*** 16개의 데이터 LInsert ***/
	printf("1. LInsert\n");
	for (int i = 1; i < 5; i++)
	{
		for (int j = 1; j < 5; j++)
		{
			ppos = (Point *)malloc(sizeof(Point));
			SetPointPos(ppos, i, j);
			LInsert(&list1, ppos);
		}
	}

	printf("LInsert된 list1 데이터의 수: %d \n", LCount(&list1));
	if(LFirst(&list1, &ppos))
	{
		ShowPointPos(ppos);
		
		while(LNext(&list1, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	/*** 16개의 데이터 SInsert ***/
	printf("2. SInsert\n");
	for (int i = 1; i < 5; i++)
	{
		for (int j = 1; j < 5; j++)
		{
			ppos = (Point *)malloc(sizeof(Point));
			SetPointPos(ppos, i, j);
			SInsert(&list2, ppos);
		}
	}

	printf("LInsert된 list2 데이터의 수: %d \n", LCount(&list2));
	if(LFirst(&list2, &ppos))
	{
		ShowPointPos(ppos);
		
		while(LNext(&list2, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	return 0;
}