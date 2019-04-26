#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "func.h"

int main()
{
    uint32_t u32Num = 0;
    uint32_t u32Num_of_ones = 0;

    while(1)
    {
        Get_number(&u32Num);
        u32Num_of_ones = Get_num_of_ones(u32Num);
        printf("The number of ones in the binary for of number %d   is   %d  \n\n\n\n",u32Num,u32Num_of_ones);
    }
}
