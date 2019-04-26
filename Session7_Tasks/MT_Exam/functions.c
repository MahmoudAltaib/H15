#include <inttypes.h>
#include <stdio.h>

#include "functions.h"

uint32_t u32Repeat_element ;

void Get_matrix(uint32_t *pu32Arr)
{
	for (u32Repeat_element = 0; u32Repeat_element < Num_of_elements; u32Repeat_element++)
	{
        printf("Enter the element number %d  :     ", u32Repeat_element);
        scanf(" %d", (pu32Arr++));
	}
}


uint32_t u32Max_occurence(uint32_t u32Arr[Num_of_elements])
{
    uint32_t u32Max_check = 0;
    uint32_t u32Max_consec = 1;
    uint32_t u32Max_consec_aid = 1;

    for(u32Max_check = 1 ; u32Max_check<Num_of_elements ; u32Max_check++)
    {
        if (u32Arr[u32Max_check] == u32Arr[u32Max_check - 1] )
        {
            u32Max_consec_aid ++;

            if( u32Max_consec_aid > u32Max_consec)
            {
                u32Max_consec ++;
            }
            else
            {

            }

        }
        else
        {
            u32Max_consec_aid = 1;
        }
    }
    return u32Max_consec;
}
