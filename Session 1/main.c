#include <stdio.h>
#include <stdlib.h>
#include "inttypes.h"
int main()
{
    /*int8_t grade = 0;
    int8_t y = 0;
    int8_t z = 0;

    printf("Please Enter The Value Of x below: \n");
    scanf("%d",&x);
    printf("Please Enter The Value Of y below: \n");
    scanf("%d",&y);

    z = x+y;

    printf("z = %03d",z);*/
    //---------------------------------------------------------------------------------------------------
    /*if(printf("Ahmed"))
    {

    }*/

    //for(;;) // This is the infinite loop in C
    //----------------------------------------------------------------------------------------------------
    /*int8_t i8Cnt;
    for(i8Cnt = 1; i8Cnt<=10 ; i8Cnt++) // i8Cnt is used just for the naming convention to reach a clean code.
    {
       printf("%d\n", i8Cnt);

    }*/
    //----------------------------------------------------------------------------------------------------
    /*float x = 5.001;
    if(x == 5.001f)
    {

        printf("Correct");
    }
    else
    {
        printf("Wrong");

    }*/
    //------------------------------------------------------------------------------------------------------
    /*uint32_t i8Cnt = 0 ;
    uint32_t input = 0 ;
    uint32_t result = 1;

    printf("Please Enter the number below: \n");
    scanf("%d", &input);

    for(i8Cnt = input; i8Cnt > 0; i8Cnt--)
    {
        result *= i8Cnt;

    }
    printf("Result = %u",result);*/
    //-----------------------------------------------------------------------------------------------------
    /*int8_t input = 0;

    printf("Please Enter the number below: \n");
    scanf("%d", &input);

    if(input % 2 == 0)
    {
        printf("Even");
    }
    else
    {
      printf("Odd");
    }*/
    //---------------------------------------------------------------------------------------------------
    /*uint32_t num1 = 0;
    uint32_t num2 = 0;
    uint32_t tmp = 0;

    printf("Please Enter the two numbers below: \n");
    scanf("%d", &num1);
    scanf("%d", &num2);

    printf("The Entered numbers in order are: %d and %d\n",num1,num2);

    tmp = num1;
    num1 = num2;
    num2 = tmp;

    printf("The swapped numbers in order are: %d and %d\n",num1,num2);*/
    //-----------------------------------------------------------------------------------------------------
    uint8_t u8Bit = 0x4;

    for(uint8_t i = 0; i < 4; i++)
    {

        u8Bit = ~u8Bit;
        u8Bit &= (1<<2);
        printf("%d\n",u8Bit);
    }

    return 0;
}
