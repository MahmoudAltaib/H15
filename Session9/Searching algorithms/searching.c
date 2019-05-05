#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "searching.h"

extern uint8_t Sort_arr_ascend(uint32_t *pu32Arr )
{
    uint8_t u8Count1 = 0;
    uint8_t u8Count2 = 0;

    for (u8Count1 = 0 ; u8Count1 < Number_of_elements ; u8Count1 ++)
    {
        for(u8Count2 = u8Count1 + 1 ; u8Count2 < Number_of_elements ; u8Count2++)
        {
            if (pu32Arr[u8Count1] > pu32Arr[u8Count2])
            {
                Swap(&pu32Arr[u8Count1],&pu32Arr[u8Count2]);
            }
            else
            {

            }
        }
    }

    return 1;
}


extern uint8_t Get_lowest_number(uint32_t *pu32Arr , uint32_t *pu32Lowest_num)
{
    uint8_t u8Count = 0;

    if (pu32Arr == 0)
    {
        return 0;
    }
    else
    {
        *pu32Lowest_num = pu32Arr[0] ;

        for (u8Count = 1; u8Count < Number_of_elements ; u8Count ++ )
        {
            if (pu32Arr[u8Count] <= *pu32Lowest_num)
            {
                *pu32Lowest_num = pu32Arr[u8Count] ;
            }
            else
            {

            }
        }
        return 1;
    }
    return 0;
}


extern void Print_array(uint32_t *pu32Arr)
{
    uint8_t u8Count = 0;

    for (u8Count = 0; u8Count < Number_of_elements ; u8Count ++)
    {
        printf("%d \n",pu32Arr[u8Count]);
    }
}


extern void Swap(uint32_t *pu32Element1,uint32_t *pu32Element2)
{
    uint32_t u32Temp_element = 0;

    u32Temp_element = *pu32Element1 ;
    *pu32Element1 = *pu32Element2 ;
    *pu32Element2 = u32Temp_element ;
}


extern void Search_num_in_array(uint32_t *pu32Arr , uint32_t u32Search_num )
{
    uint8_t u8Count = 0 ;

    for (u8Count = 0 ; u8Count < Number_of_elements ;u8Count ++)
    {
        if (pu32Arr[u8Count] == u32Search_num)
        {
            printf("\n\nThe number you are searching for has an index   %d  \n\n",u8Count);
        }
        else
        {

        }
    }

}


extern void Check_repetition(uint32_t *pu32Arr )
{
    uint8_t u8Count = 0;

    for (u8Count = 0 ;u8Count < Number_of_elements ; u8Count ++)
    {

    }
}
