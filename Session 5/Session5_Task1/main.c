#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

uint32_t mul_for_loop(uint32_t u32Num1 ,uint32_t u32Num2);

int main()
{
    uint32_t u32Result= 0;
    uint32_t u32Num1 = 0;
    uint32_t u32Num2 = 0;

    printf("Enter the first number :  ");
    scanf("%d",&u32Num1);

    printf("Enter the second number :  ");
    scanf("%d",&u32Num2);

	u32Result = mul_for_loop(u32Num1,u32Num2);
  printf("The result is %d",u32Result);
    return 0;
}


uint32_t mul_for_loop(uint32_t u32Num1 ,uint32_t u32Num2)
{
    int8_t i8Repeat =0;
    uint32_t u32Result =0;

    for (i8Repeat =0 ; i8Repeat<u32Num2 ; i8Repeat++)
    {
        u32Result +=u32Num1;
    }

    return u32Result ;
}
