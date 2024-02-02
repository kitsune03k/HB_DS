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
            if (tmp[arr[tmp[j]]] >= arr[tmp[j+1]])
            {
                Swap(tmp, j, j+1);
            }
        }
    }

    printf("after bubblesort\n");
	printf("idx : %d %d %d\nvalue : %d %d %d\n", tmp[0], tmp[1], tmp[2], arr[tmp[0]], arr[tmp[1]], arr[tmp[2]]);

	printf("pidx : %d\n", tmp[1]);

	return tmp[1]; // pivot의 index 반환
}

int main(void)
{
	int arr[15] = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    MedianOfThree(arr, 0, sizeof(arr)/sizeof(int)-1);

	return 0;
}