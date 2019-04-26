#include <stdio.h>
#include <stdlib.h>
#include "inttypes.h"

int main()
{
    uint64_t i8A= 0 , i8B=0 , Cnt =0 , i8Result = 0;

    printf("Please Enter Value A = \n ");
    scanf("%d",&i8A);


    printf("Please Enter Value B = \n ");
    scanf("%d",&i8B);

    for(Cnt=1 ; Cnt <= i8B ; Cnt++)
    {
        i8Result = i8Result+i8A ;


    }
printf("Value of R = %d \n", i8Result);

    return 0;
}

