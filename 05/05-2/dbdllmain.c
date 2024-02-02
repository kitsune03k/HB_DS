#include "DBDLinkedList.h"
#include <stdio.h>

void showallfromhead(List *list)
{
    Data data;
    int length = LCount(list);

    if (LFirst(list, &data))
    {
        printf("%d(head)", data);

        for (int i = 0; i < LCount(list) - 1; i++)
        {
            if (LNext(list, &data))
                printf(" -> %d", data);
        }
        printf("(tail)\n");
    }
}

void showallfromtail(List *list)
{
    Data data;
    int length = LCount(list);

    if (LLast(list, &data))
    {
        printf("%d(tail)", data);

        for (int i = 0; i < LCount(list) - 1; i++)
        {
            if (LPrev(list, &data))
                printf(" -> %d", data);
        }
        printf("(head)\n");
    }
}

void showhead(List *list)
{
    Data data;
    LFirst(list, &data);
    printf("head : %d\n", data);
}

void showtail(List *list)
{
    Data data;
    LLast(list, &data);
    printf("tail : %d\n", data);
}

void showht(List *list)
{
    Data data;
    LFirst(list, &data);
    printf("head : %d / ", data);
    LLast(list, &data);
    printf("tail : %d", data);
}

void delodd(List *list)
{
    Data data;
    int length = LCount(list);

    printf("\n*** delodd *** : ");

    if (LFirst(list, &data))
    {
        if (data % 2 == 1)
        {
            int dd = LRemove(list);
            printf("(%d) ", dd);
        }

        while (LNext(list, &data))
        {
            if (data % 2 == 1)
            {
                int dd = LRemove(list);
                printf("(%d) ", dd);
            }
        }
    }
    printf("deleted\n");
}

void deleven(List *list)
{
    Data data;
    int length = LCount(list);

    printf("\n*** deleven *** : ");

    if (LFirst(list, &data))
    {
        if (data % 2 == 0)
        {
            int dd = LRemove(list);
            printf("(%d) ", dd);
        }
        while (LNext(list, &data))
        {
            if (data % 2 == 0)
            {
                int dd = LRemove(list);
                printf("(%d) ", dd);
            }
        }
    }
    printf("deleted\n");
}

int main(void)
{
    List list1, list2;
    ListInit(&list1);
    ListInit(&list2);

    for (int i = 1; i < 9; i++)
    {
        LInsertHead(&list1, i);
        LInsertTail(&list2, i + 8);
    }
    // list1 : head(dmy)->8->7->...->2->1->tail(dmy)
    // list2 : head(dmy)->9->10->...->15->16-> tail(dmy)



    printf("***** list1 *****\n");

    showallfromhead(&list1);
    printf("length : %d\n", LCount(&list1));
    showht(&list1);

    delodd(&list1); // 홀수 삭제 -> 짝수만 남음
    // 8->6->4->2

    showallfromhead(&list1);
    printf("length : %d\n", LCount(&list1));
    showht(&list1);



    printf("\n\n***** list2 *****\n");

    showallfromhead(&list2);
    printf("length : %d\n", LCount(&list2));
    showht(&list2);

    deleven(&list2); // 짝수 삭제 -> 홀수만 남음
    // 9->11->13->15

    showallfromhead(&list2);
    printf("length : %d\n", LCount(&list2));
    showht(&list2);
    printf("\n");
}