#include "Linked_List.h"
#include <stdio.h>
#include "string.h"
#include <stdlib.h>

int linearsearch(int A)
{
    printf("enter A");
    scanf("%d",&A);
    int arr[7]={5,6,8,9,3,4,8,6};
    int i =0 ;

    for(i=0;i<7;i++)
        if(A == arr[i])
    {
        printf("%d \n",A);
    }


return 0;

}
