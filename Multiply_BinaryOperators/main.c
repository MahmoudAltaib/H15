#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
uint8_t   u8num1=0;
uint8_t  u8num2=0;
uint16_t  u16Res=0;
uint32_t  u32x=0;

int main()
{

    printf("Enter first number!\n");
    scanf("%u",&u8num1);
    printf("Enter second number!\n");
    scanf("%u",&u8num2);

        if (u8num2%2==0)
        {
          u32x=(u8num1<<(u8num2/2));
            u16Res=u32x;
            printf("Answer=%d\n",u16Res);
        }
        else if (u8num2%2==1);
        {
            u32x=(u8num1<<(u8num2/2));
            u16Res=u32x+u8num1;
            printf("Answer=%d\n",u16Res);
        }


    return 0;
}
