#include <stdio.h>
#include <string.h>
#include "CLL_Company.h"

void whodangjik(List * list, char name[], int dayafter)
{
	Employee data;

	if (LFirst(list, &data))
	{
		// head에 찾는 내용이 있으면
		if (strcmp(name, data.name) == 0)
		{
			;
		}
		// head에 찾는 내용이 없으면 
		else
		{
			for (int i = 0; i < LCount(list)-1; i++)
			{
				if (LNext(list, &data))
				{
					if (strcmp(name, data.name) == 0)
					{
						break;
					}
				}
			}
		}
	}
	// 여기까지 진행되었으면, data는 이름으로 검색한 node의 값을 가지고있음.

	for (int i = 0; i < dayafter; i++)
	{
		LNext(list, &data);
	}

	printf("%s의 %d일 뒤 당직은 %s입니다\n", name, dayafter, data.name);
}

void showall(List * list)
{
	Employee data;

	if (LFirst(list, &data))
	{
		printf("[%s, %d, %d]\n", data.name, data.id, data.age);
		
		for (int i = 0; i < LCount(list) - 1; i++)
		{
			if (LNext(list, &data))
				printf("[%s, %d, %d]\n", data.name, data.id, data.age);
		}
	}
}

void showhead(List * list)
{
	Employee data;
	data = list->tail->next->data;
	printf("head : %s, %d, %d\n", data.name, data.id, data.age);
}

void showtail(List * list)
{
	Employee data;
	data = list->tail->data;
	printf("tail : %s, %d, %d\n", data.name, data.id, data.age);
}

int main(void)
{
	// 원형 연결 리스트의 생성 및 초기화 ///////
	List Company;
	int i, nodeNum;
	ListInit(&Company);

	// 리스트에 4개의 데이터를 저장 ///////
	Employee ee[4] = {
		{"Andy", 1001, 29}, {"Chris", 1002, 33}, {"Edward", 1003, 34}, {"Jeff", 1004, 25}
	};

	LInsert(&Company, ee[0]); 
	LInsert(&Company, ee[1]); 
	LInsert(&Company, ee[2]); 
	LInsert(&Company, ee[3]); 

	showall(&Company);

	showhead(&Company);
	showtail(&Company);

	for (int i=0; i<10; i++)
	{
		whodangjik(&Company, "Andy", i+1);
	}
	return 0;
}