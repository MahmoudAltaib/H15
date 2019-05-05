#include "Selection_sorting.h"


extern void Swap(uint32_t *pu32Element1 ,uint32_t *pu32Element2)
{
    uint32_t u32Temp_element = 0;

    u32Temp_element = *pu32Element1 ;
    *pu32Element1 = *pu32Element2 ;
    *pu32Element2 = u32Temp_element ;

}


extern void Selection_sort_array(uint32_t *pu32Arr)
{
    uint8_t u8Count1 = 0;
    uint8_t u8Count2 = 0;
    uint32_t u32Lowest_num = 0;
    uint32_t u32Temp_element = 0;

    for (u8Count1 = 0 ; u8Count1 < Number_of_elements ; u8Count1++)
    {

        u32Lowest_num = pu32Arr[u8Count1];

        for (u8Count2 = u8Count1 ; u8Count2 < Number_of_elements ; u8Count2++)
        {

            if (pu32Arr[u8Count2] <= u32Lowest_num )
            {
                u32Lowest_num = pu32Arr[u8Count2];
                u32Temp_element = u8Count2 ;
            }
            else
            {

            }
        }
        Swap(&pu32Arr[u8Count1]  , &pu32Arr[u32Temp_element]);

    }
}


extern void Bubble_sort_array(uint32_t *pu32Arr)
{
    uint8_t u8Count1 = 0;
    uint8_t u8Count2 = 0;

    for (u8Count1 = 0 ; u8Count1 < Number_of_elements ; u8Count1++)
    {
        for (u8Count2 = u8Count1 ; u8Count2 < Number_of_elements ; u8Count2++)
        {
            if (pu32Arr[u8Count2] < pu32Arr[u8Count1])
            {
                Swap(&pu32Arr[u8Count1] , &pu32Arr[u8Count2]);
            }
        }

    }
}


extern void Merge_sort_array(uint32_t *pu32Arr1 , uint32_t *pu32Arr2)
{
    uint8_t u8Count1 = 0;
    uint8_t u8Count2 = 0;


    for (u8Count1 = 0 ; u8Count1 < Number_of_itterations ; u8Count1 ++)
    {
    }
}
