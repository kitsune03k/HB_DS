#include <stdio.h>

void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}	

int MedianOfThree(int arr[], int left, int right)
{
	int tmp[3] = {left, (left+right)/2, right};
	printf("idx : %d %d %d\nvalue : %d %d %d\n", tmp[0], tmp[1], tmp[2], arr[tmp[0]], arr[tmp[1]], arr[tmp[2]]);

	// medium array bubblesort
    for (int i = 0; i < 3 - 1; i++)
    {
        for (int j = 0; j < 3 - 1 - i; j++)
        {
            if (tmp[arr[tmp[j]]] > arr[tmp[j+1]])
            {
                Swap(tmp, j, j+1);
            }
        }
    }

    printf("after bubblesort\n");
	printf("idx : %d %d %d\nvalue : %d %d %d\n", tmp[0], tmp[1], tmp[2], arr[tmp[0]], arr[tmp[1]], arr[tmp[2]]);

	return tmp[1]; // pivot의 index 반환
}

int Partition(int arr[], int left, int right)
{
	int pIdx = MedianOfThree(arr, left, right); // index가 아닌, 크기를 따져야하는 변수
	int pivot = arr[pIdx];

	int low = left+1;
	int high = right;

	Swap(arr, left, pIdx);

	printf("pidx : %d, pivot : %d \n\n", pIdx, pivot);

	while(low <= high)    // 교차되지 않을 때까지 반복
	{	
		/*
		while(pivot > arr[low])
			low++;

		while(pivot < arr[high])
			high--;
		*/
		
		while(pivot >= arr[low] && low <= right)
			low++;

		while(pivot <= arr[high] && high >= (left+1))
			high--;
		

		if(low <= high)    // 교차되지 않은 상태라면 Swap 실행
			Swap(arr, low, high);    // low와 high가 가리키는 대상 교환
	}

	Swap(arr, left, high);    // 피벗과 high가 가리키는 대상 교환
	return high;    // 옮겨진 피벗의 위치 정보 반환
}

void QuickSort(int arr[], int left, int right)
{
	if(left < right) // 재귀 탈출조건 left >= right
	{
		int pivot = Partition(arr, left, right);    // 둘로 나눠서 
		QuickSort(arr, left, pivot-1);    // 왼쪽 영역을 정렬
		QuickSort(arr, pivot+1, right);    // 오른쪽 영역을 정렬
	}
}

int main(void)
{
	int arr[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

	int len = sizeof(arr) / sizeof(int);
	int i;

	QuickSort(arr, 0, sizeof(arr)/sizeof(int)-1);

	for(i=0; i<len; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}