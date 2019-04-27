#include "Searching.h"
#include <inttypes.h>

extern int LinearSearch(int x, int s, int *arr, int *index)
{
for (int i = 0; i <= s; i++)
{
if(x == (*(arr+i)) )
{
    *index = i;
    return 1;
}
}
return -1;
}

extern int Is_Duplicated(int x, int s, int *arr, int *n_duplications)
{ uint8_t u8Cnt = 0;
    for(int i = 0; i <= s; i++)
    {
        for(int j = i + 1; j <= s; j++)
        {
            if(arr[i] == arr[j])
            {
                u8Cnt++;
            }
        }
    }
    if(u8Cnt == 0)
     {
         return 0;
     }
    else
    {
        *n_duplications = u8Cnt;
        return 1;
    }
return 0;
}
