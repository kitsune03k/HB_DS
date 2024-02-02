#include <stdio.h>
#include <string.h>

#include "PriorityQueue.h"

int DataPriorityComp(char * ch1, char * ch2)
{
	return strlen(ch2)-strlen(ch1);
}

int main(void)
{
	PQueue pq;
	PQueueInit(&pq, DataPriorityComp);

	PEnqueue(&pq, "a");
	PEnqueue(&pq, "aa");
	PEnqueue(&pq, "aaa");
	PEnqueue(&pq, "aaaa");
	PEnqueue(&pq, "aaaaa");

	while(!PQIsEmpty(&pq))
		printf("%s \n", PDequeue(&pq));

	return 0;
}
