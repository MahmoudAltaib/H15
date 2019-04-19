#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

uint32_t u32Get_number();

int main()
{
    uint32_t u32Num1 = 0;

    uint32_t (*pfGet_number)() = 0;

    pfGet_number = & u32Get_number ;

    printf("Enter Number 1 :     ");

    u32Num1 = (*pfGet_number)();

    printf("\nNumber 1  =   %d ",u32Num1) ;


}

uint32_t u32Get_number()
{
   uint32_t u32Num = 0;

   scanf("%d",&u32Num);

   return u32Num ;
}

