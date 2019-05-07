//
//  main.c
//  selectionsortingalgorithm
//
//  Created by Ahmed Abdellatif on 03/05/2019.
//  Copyright © 2019 Ahmed Abdellatif. All rights reserved.
//
#include "sorting.h"

extern void swap(int *px, int *py)
{
    int temp = *px;
    *px = *py;
    *py = temp;
}

extern void selSort(int arr[], int n)
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
