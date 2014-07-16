/**************************************************************
 *
 *            FileName: MergeSort.c
 *            Des:      merge sort(recursion method and 
 *                      non-recursion method)
 *            Author:   me
 *            Created:  2014.07.05
 *            Modified: 2014.07.06
 *            Version:  0.0.1
 *
 **************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/malloc.h>

void merge(int src[], int low, int high, int mid)
{
    int i = low;
    int k = 0;
    int j = mid + 1;
    int *temp = (int *)malloc(sizeof(int) * (high - low + 1));

    if(!temp)
    {
        printf("Error: malloc temp.(merge)\n");
        return;
    }
    
    while( (i <= mid) && (j <= high))
    {
        if(src[i] < src[j])
        {
            temp[k++] = src[i++];
        }
        else
        {
            temp[k++] = src[j++];
        }
    }

    while(i <= mid)
    {
        temp[k++] = src[i++];
    }
    while(j <= high)
    {
        temp[k++] = src[j++];
    }
    for (i = low, k = 0; i <= high ; ++i, ++k)
    {
        src[i] = temp[k];
    }

    free(temp);
}

void MSort( int arr[], int low, int high)
{
    int mid = (low + high) / 2;
    if (low == high)
    {   
        arr[low] = arr[low];
    }
    else
    {
        MSort(arr, low, mid);
        MSort(arr, mid + 1, high);
        merge(arr, low, high, mid);
    }

}

void MergeSort(int arr[], int low, int high, int len)
{
    MSort( arr, low, high);
} 

void MergeSort_NonRecursion(int arr[], int max_size)
{
    int k = 1;
    int low = 0;
    int mid = 0;
    int high = 0;
    while (k < max_size)
    {
        low = 0;
        while(low + k < max_size)
        {
            mid = low + k - 1;
            high = mid + k;
            if (high > max_size - 1)
            {
                high = max_size - 1;
            }
            merge(arr, low, high, mid);
            low = high + 1;
        }

        k *= 2;
    }
}

int main(void)
{
    int arr[10];
    int i = 0;
    int max_size = 10;

    srand((unsigned)time(NULL));

    for(i = 0; i < max_size; i++)
    {
        arr[i] = rand() % 100;
    }

    printf("Before sort:\n");
    for (i = 0; i < max_size; i++)
    {
        printf("%d ", arr[i]);
    }

    //MergeSort( arr, 0, max_size - 1, max_size);
    MergeSort_NonRecursion(arr, max_size);

    printf("\nAfter sort:\n");
    for (i = 0; i < max_size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
