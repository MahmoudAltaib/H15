/* MergeSortModular , ref. Geeksforgeeks */
#include <stdio.h>
#include "mergesort.h"

int main(int argc, const char * argv[])
{
    int arr[] = {10, 5, 3, 20, 21, 15 ,15};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i = 0;
    mergeSort(arr,0, n-1);
    printf("Sorted array: \n");
    for (i= 0 ; i<n ; i++)
    {
        printf("%d\t",arr[i]);
    }
    return 0;
}
