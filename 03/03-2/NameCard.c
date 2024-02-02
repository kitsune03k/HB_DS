#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"

// NameCard 구조체 변수의 동적 할당 및 초기화 후 주소 값 반환
NameCard * MakeNameCard(char * name, char * phone)
{
    NameCard* address = (NameCard*)malloc(sizeof(NameCard));
    strcpy(address->name, name);
    strcpy(address->phone, phone);
    return address;
}

// NameCard 구조체 변수의 정보 출력
void ShowNameCardInfo(NameCard * address)
{
    printf("%s : %s\n", address->name, address->phone);
}

// 이름이 같으면 0, 다르면 0이 아닌 값 반환
int NameCompare(NameCard * address, char * name)
{
    return strcmp(address->name, name);
}

// 전화번호 정보를 변경
void ChangePhoneNum(NameCard * address, char * phone)
{
    strcpy(address->phone, phone);
}