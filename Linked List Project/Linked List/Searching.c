#include "Searching.h"
#include "string.h"
#include "stdlib.h"
#include <stdio.h>

extern uint8_t linearSearch(uint8_t *arr, uint8_t x, uint8_t *result)
{

    uint8_t i;

    for(i = 0; i < 6; i++)
    {
        if((*(arr + i))== x)
        {
            *result = i;
            return 1;
        }

    }
            return 0;
}

