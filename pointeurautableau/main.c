//
//  main.c
//  pointeurautableau
//
//  Created by Ahmed Abdellatif on 26/04/2019.
//  Copyright © 2019 Ahmed Abdellatif. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[2][3] = {0};
    int (*pArr)[3] = arr;
    int i =0;
    int j =0;
    int k =0;
    for (i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {
            *(*(pArr+i)+j) =k;
            k++;
        }
    }
    for (i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d %d\n",*(*(pArr+i)+j),arr[i][j]);
        }
    }
    return 0;
}
