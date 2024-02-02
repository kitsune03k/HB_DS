#include <stdio.h>
#include "CLinkedList.h"

#if DEBUG
void showall(List *list)
{
	Data data;
	int length = LCount(list);

	if (LFirst(list, &data))
	{
		printf("%d(top)", data);

		for (int i = 0; i < LCount(list) - 1; i++)
		{
			if (LNext(list, &data))
				printf(" -> %d", data);
		}
		printf("(bottom)\n");
	}
	else
	{
		printf("** NOTHING TO SHOW **\n");
	}
}
#endif

void prnempstk(Stack * pstack)
{
	printf("is stack empty? %s\n", SIsEmpty(pstack) ? "True" : "False");
}

int main(void)
{
	Stack s1;
	SInit(&s1);
	prnempstk(&s1);

	for (int i = 0; i < 10; i++)
	{
		SPush(&s1, i + 10);
		printf("(%d) pushed into stack\n", i + 10);
	}

#if DEBUG
	showall(&s1);
#endif

	prnempstk(&s1);
	printf("top is %d\n", SPeek(&s1));

	for (int i = 0; i < 5; i++)
	{
		printf("(%d) popped from stack\n", SPop(&s1));
	}

#if DEBUG
	showall(&s1);
#endif

	prnempstk(&s1);
	printf("top is %d\n", SPeek(&s1));

	for (int i = 0; i < 5; i++)
	{
		printf("(%d) popped from stack\n", SPop(&s1));
	}

#if DEBUG
	showall(&s1);
#endif

	prnempstk(&s1);
	if(SPeek(&s1) != -1)
		printf("top is %d\n", SPeek(&s1));
}