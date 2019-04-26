#include <stdio.h>
#include <stdlib.h>
#include "inttypes.h"

int main()
{
    uint32_t  ui32No = 0;

    scanf("%d",&ui32No);

    if ( ui32No & 1 == 1 )
    {
        printf("Odd\n");
    }
    else
    printf("Even");
    return 0;
}
