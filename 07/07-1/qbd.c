#include "DequeBaseQueue.h"

typedef DLDeque Queue; 
// Deque.h에서 DLDeque는 typedef Deque, 이 파일에서 Queue

void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);
void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data QPeek(Queue * pq);

void PrnQEmpty(Queue * pq);
void PrnQPeek(Queue * pq);

int main(void)
{
    Queue q1;
    QueueInit(&q1);

    printf("queue inited\n");
    PrnQEmpty(&q1);

    for (int i = 0; i < 5; i++)
    {
        Enqueue(&q1, i+1);
        printf("(%d) Enqueued\n", i+1);
    }
    printf("after enqueue, ");
    PrnQPeek(&q1);
    PrnQEmpty(&q1);

    printf("\n");

    for (int i = 0; i < 5; i++)
    {
        Data ret = Dequeue(&q1);
        printf("(%d) Dequeued, ", ret);
        PrnQPeek(&q1);
    }
    printf("after enqueue, ");

    return 0;
}

void QueueInit(Queue * pq)
{
    DequeInit(pq);
}

int QIsEmpty(Queue * pq)
{
    return DQIsEmpty(pq);
}

void Enqueue(Queue * pq, Data data)
{
    DQAddFirst(pq, data);
}

Data Dequeue(Queue * pq)
{
    return DQRemoveFirst(pq);
}

Data QPeek(Queue * pq)
{
    return DQGetFirst(pq);
}

void PrnQEmpty(Queue * pq)
{
    if (QIsEmpty(pq))
    {
        printf("QIsEmpty : Queue is empty\n");
    }
    else
    {
        printf("QIsEmpty : Queue is not empty\n");
    }
}

void PrnQPeek(Queue * pq)
{
    printf("QPeek : %d\n", QPeek(pq));
}