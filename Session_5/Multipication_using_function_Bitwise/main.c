#include <stdio.h>
#include <stdlib.h>
#include "inttypes.h"


int main()
{
    uint64_t i64A = 0 , i64B = 0 , i64Ans = 0 , Cnt =0 ;

    printf("enter A = \n");
    scanf("%d", &i64A);

    printf("enter A = \n");
    scanf("%d", &i64B);





    i64Ans = add(i64A , i64B);



    printf("Result = %d",i64Ans);


    return 0;
}
int add (uint64_t x , uint64_t y )
{
   uint64_t i8Result = 0 , Cnt = 0 ;

    for(Cnt=1 ; Cnt <= y ; Cnt++)
    {
        i8Result = i8Result+ x ;


    }


    return i8Result ;
}

