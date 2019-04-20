#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "functions.h"

int main ()
{
    uint32_t u32Num = 0;
    uint32_t (*pfu32Get_number)() = 0;

    pfu32Get_number = & u32Get_number;

    printf("Enter the number you want ");
    u32Num = (*pfu32Get_num)();

    printf("\n\nThe entered number is %d",u32Num);
}
