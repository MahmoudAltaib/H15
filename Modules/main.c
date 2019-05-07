//  Created by Ahmed Abdellatif on 03/05/2019.
//  Copyright © 2019 Ahmed Abdellatif. All rights reserved.
//
#include "sorting.h"   // .h seulement
#include <stdio.h>

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
