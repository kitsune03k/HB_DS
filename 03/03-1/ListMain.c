#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
	/** ArrayList의 생성 및 초기화 **/
	List list03; // 배열, 커서위치, 원소갯수를 가지고있는 구조체
	int data; // 값 불러와서 저장되는 int; 계속 바뀜
	ListInit(&list03);

	/** 1. 1-9 저장 **/
	for(int i = 1 ; i < 10 ; i++){
        LInsert(&list03, i);
    }

    int sum = 0;

    /** 2. 참조하여 합 구하기 **/
    //argv = (List list03의 주소, int data의 주소)
	if(LFirst(&list03, &data)){
        // data = list03[0], TRUE or FALSE 반환
        sum = sum + data;

		while(LNext(&list03, &data))  // 두 번째 이후의 데이터 조회
            // LNext의 반환값이 while(0)일때 while(0)이 되어 반복문 종료
			sum = sum + data;
	}
	printf("sum : %d\n", sum);

    /** 3. 2의배수, 3의배수 리스트에서 삭제**/
	if(LFirst(&list03, &data)){
		if(data%2 == 0 || data%3 == 0){
            LRemove(&list03);
        }
		
		while(LNext(&list03, &data)) {
            if (data % 2 == 0 || data % 3 == 0) {
                LRemove(&list03);
            }
        }
	}

    /** 4. 삭제 후 저장된 데이터 전체 출력 **/
    printf("after remove data count: %d \n", LCount(&list03));

    if(LFirst(&list03, &data)){
        // data = list03[0], TRUE or FALSE 반환
        printf("%d ", data);

        while(LNext(&list03, &data))  // 두 번째 이후의 데이터 조회
            // LNext의 반환값이 while(0)일때 while(0)이 되어 반복문 종료
            printf("%d ", data);
    }
}