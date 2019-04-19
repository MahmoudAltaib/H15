#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int32_t i32Add(int32_t a,int32_t b,int32_t *c);

int main()
{
    int32_t i32Num1 = 10;
    int32_t i32Num2 = 15;
    int32_t i32Result = 0;

    i32Add(i32Num1,i32Num2,&i32Result);

    printf("Result  = %d \n",i32Result);

    return 0;
}


int32_t i32Add(int32_t a,int32_t b ,int32_t *c)
{
    *c = a+b;
}
