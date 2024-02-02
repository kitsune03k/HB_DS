#include <stdio.h>

#include "ArrayList.h" // NameCard.h  포함

int main(void)
{
    /*** ArrayList의 생성 및 초기화 ***/
    List Contacts;
    ListInit(&Contacts);
    NameCard* address; // 계속 바뀜, 포인터값 저장
    // 포인터가 가르키는 값의 연산은 항상 NameCard.h에서 정의된 함수로

    /** 1. 총 3명의 리스트를 저장 **/
    LInsert(&Contacts, MakeNameCard("adam", "01012345678"));
    LInsert(&Contacts, MakeNameCard("bryan", "01023456789"));
    LInsert(&Contacts, MakeNameCard("clara", "01034567890"));

    printf("\n****** Contacts ******\n");
    if(LFirst(&Contacts, &address)) // 0 or 1 반환
    {
        ShowNameCardInfo(address);

        while(LNext(&Contacts, &address))
        {
            ShowNameCardInfo(address);
        }
    }
    printf("**********************\n\n");

    /** 2. 이름 탐색하여 이름, 전화번호 출력 **/
    if(LFirst(&Contacts, &address)) // 0 or 1 반환
    {
        printf("searching adam...\n");

        if(NameCompare(address, "adam") == 0)
        {
            ShowNameCardInfo(address);
            printf("\n");
        }
        else
        {
            while (LNext(&Contacts, &address))
            {
                if(NameCompare(address, "adam") == 0)
                {
                    ShowNameCardInfo(address);
                    printf("\n");
                }
            }
        }
    }

    /** 3. 이름 탐색하여 전화번호 변경 **/
    if(LFirst(&Contacts, &address)) // 0 or 1 반환
    {
        printf("searching bryan...\n");

        if(NameCompare(address, "bryan") == 0)
        {
            ChangePhoneNum(address, "76012345678");
            ShowNameCardInfo(address);
        }
        else
        {
            while (LNext(&Contacts, &address))
            {
                if(NameCompare(address, "bryan") == 0)
                {
                    ChangePhoneNum(address, "76012345678");
                    printf("Number Changed!\n");
                    ShowNameCardInfo(address);
                }

            }
        }
    }

    printf("\n****** Contacts ******\n");
    if(LFirst(&Contacts, &address)) // 0 or 1 반환
    {
        ShowNameCardInfo(address);

        while(LNext(&Contacts, &address))
        {

            ShowNameCardInfo(address);
        }
    }
    printf("**********************\n\n");

    /** 4. 이름 탐색하여 정보 삭제 **/
    if(LFirst(&Contacts, &address))
    {
        printf("deleting clara...\n");

        if(NameCompare(address, "clara") == 0)
        {
            LRemove(&Contacts);
        }
        else
        {
            while (LNext(&Contacts, &address))
            {
                if(NameCompare(address, "clara") == 0)
                {
                    LRemove(&Contacts);
                }
            }
        }
    }

    printf("\n****** Contacts ******\n");
    if(LFirst(&Contacts, &address)) // 0 or 1 반환
    {
        ShowNameCardInfo(address);

        while(LNext(&Contacts, &address))
        {
            ShowNameCardInfo(address);

        }
    }
    printf("**********************\n\n");
}