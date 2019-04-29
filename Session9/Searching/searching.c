#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "searching.h"

extern uint32_t linear_search(int32_t *pi32Arr,int32_t i32Num, uint32_t *pResult)
{
    uint32_t u32Count = 0;

    for (u32Count = 0; u32Count < Num_of_elements;u32Count++)
    {
        if(i32Num == pi32Arr[u32Count])
        {
            *pResult = u32Count ;
            return 1 ;
        }
        else
        {

        }
    }

    return 0;
}
