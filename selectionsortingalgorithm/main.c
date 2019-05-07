//
//  main.c
//  selectionsortingalgorithm
//
//  Created by Ahmed Abdellatif on 03/05/2019.
//  Copyright © 2019 Ahmed Abdellatif. All rights reserved.
//

#include <stdio.h>
    void swap(int *px, int *py)
    {
        int temp = *px;
        *px = *py;
        *py = temp;
    }
    
    void selSort(int arr[], int n)
    {
        int i, j, min;

        for (i = 0; i < n-1; i++)
        {
            min = i;
            for (j = i+1; j < n; j++)
                if (arr[j] < arr[min])
                    min = j;
            swap(&arr[min], &arr[i]);
        }
    }

    int main(int argc, const char * argv[])
    {
        int arr[] = {10, 5, 3, 20, 21, 17 ,15};
        int n = sizeof(arr)/sizeof(arr[0]);
        int i = 0;
        selSort(arr, n);
        printf("Sorted array: \n");
        for (i= 0 ; i<n ; i++)
        {
            printf("%d\t",arr[i]);
        }
        return 0;
    }
