#include <stdio.h>
#include<stdlib.h>
#include<inttypes.h>


uint8_t add(uint8_t u8Num1 , uint8_t u8Num2);

int main()
{
    uint8_t u8Result = 0;
    uint8_t u8Repeat = 0;

    for (u8Repeat = 0 ; u8Repeat < 3 ;u8Repeat ++)
    {
        u8Result = add(u8Repeat,1);
        printf("The result num %d is   %d   \n",u8Repeat,u8Result);
    }
}

uint8_t add(uint8_t u8Num1 , uint8_t u8Num2)
{
   static uint8_t u8Counter = 0;

    u8Counter ++;

    printf("Number of counts  =   %d   \n",u8Counter);

    return u8Num1+u8Num2;
}
