//
//  main.c
//  2darr
//
//  Created by Ahmed Abdellatif on 20/04/2019.
//  Copyright © 2019 Ahmed Abdellatif. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[2][3] = {{0,1,2},{3,4,5}};
    int arr2[2][3]={0};
    int **pvar=0;
    int i =0;
    int j =0;
    int k =0;
    printf("%d\t",arr[0][0]);
    printf("%d\t",arr[0][1]);
    printf("%d\n",arr[0][2]);
    printf("%d\t",arr[1][0]);
    printf("%d\t",arr[1][1]);
    printf("%d\t\n",arr[1][2]);
    // arr[0] =1 // compile error writes to address of 1st array
    printf("%p\n",arr[0]); //address of 1st array 1st dimension
    printf("%p\n",arr[1]); //address of 2nd array = add of last of add of 1st array + 0x
    printf("%p\n",&arr[1][0]);
    for (i=0;i<2;i++)
    {
        for (j=0;j<3;j++)
        {
            arr[i][j]=k++;
            printf("%d \t",arr[i][j]);
        }
    }
    pvar=arr2;
    for (i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {
            *((*(pvar+i))+j)=k++;   //* access the add while not using it accesses the value itself
            printf("%d \t",arr2[i][j]);
        }
    }
    return 0;
}
