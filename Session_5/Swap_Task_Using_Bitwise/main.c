#include <stdio.h>
#include <stdlib.h>
#include "inttypes.h"


int main()
{
    int A = 0 , B = 0 ;

    printf("please enter A = ",A);
    scanf("%d",&A);

    printf("please enter B = ",B);
    scanf("%d", &B);

    A = A ^ B ;
    B = A ^ B ;
    A = A ^ B;
printf("A =%d \n",A);
printf("B = %d \n" ,B);
    return 0;
}
