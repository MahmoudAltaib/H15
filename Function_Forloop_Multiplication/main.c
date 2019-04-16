#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
int i=0;
int Q;
uint8_t  u8num1=0;
uint8_t  u8num2=0;
uint16_t u16Res=0;
int mul (int x,int y)
{for(i=0;i<u8num2;i++)
        {
           u16Res=u16Res+u8num1;
        }
}


int main()
{
    printf("Enter first Number!\n",u8num1);
    scanf("%u",&u8num1);
    printf("Enter second number\n",u8num2);
    scanf("%u",&u8num2);
    Q= mul(u8num1,u8num2);
        printf("Result of Multiply =%u\n",u16Res);

    return 0;
}
