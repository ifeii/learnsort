/**************************************************************
 *
 *            FileName: SelectSort.c
 *            Des:      Select sort
 *
 *            Author:   me
 *            Created:  2014.07.06
 *            Modified: 2014.07.06
 *            Version:  0.0.1
 *
 **************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void SelectSort(int arr[], int max_size)
{
	int i = 0;
	int j = 0;
	int min = 0;

	for (i = 0; i < max_size - 1; ++i)
	{
		min = i;
		for (j = i + 1; j < max_size; ++j)
		{
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}
		if (i != min)
		{
			int temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}
}

int main(void)
{
	int arr[10];
	int max_size = 10;
	int i = 0;
	srand((unsigned)time(NULL));

	printf("Before sort: \n");
	for(i = 0; i < max_size; ++i)
	{
		arr[i] = rand() % 1000;
		printf("%d ", arr[i]);
	}
	printf("\nAfter sort: \n");

	SelectSort(arr, max_size);

	for (i = 0; i < max_size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}