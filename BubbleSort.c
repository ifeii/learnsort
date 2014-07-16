/**************************************************************
 *
 *            FileName: BublleSort.c
 *            Des:      Bublle sort
 *                      improved with flag 
 *            Author:   me
 *            Created:  2014.07.06
 *            Modified: 2014.07.06
 *            Version:  0.0.1
 *
 **************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void BubbleSort(int arr[], int max_size)
{
	int i = 0;
	int j = 0;
	int flag = 1;

	for (i = 0; i < max_size - 1 && flag == 1; ++i)
	{
		flag = 0;
		for (j = max_size - 1; j > i; --j)
		{
			if (arr[j - 1] > arr[j])
			{
				int temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;

				flag = 1;
			}
		}
	}
}

int main(void)
{
	int arr[100];
	int max_size = 100;
	int i = 0;
	srand((unsigned)time(NULL));

	printf("Before sort: \n");
	for(i = 0; i < max_size; ++i)
	{
		arr[i] = rand() % 1000;
		printf("%d ", arr[i]);
	}
	printf("\nAfter sort: \n");

	BubbleSort(arr, max_size);

	for (i = 0; i < max_size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
