#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "func.h"

void Get_number(uint32_t *pu32Arr)
{
    printf("Enter the  number  :     ");
    scanf(" %d", pu32Arr);
}

uint32_t  Get_num_of_ones (uint32_t u32Num )
{
    uint32_t u32Repeat = 0;
    uint32_t pu32Num_ones = 0;

    for (u32Repeat = 0;u32Repeat<Num_of_bits;u32Repeat++)
    {
        if (u32Num & 1)
        {
            pu32Num_ones ++ ;
        }
        else
        {

        }

        u32Num = u32Num >>1 ;
    }
    return pu32Num_ones;

}
