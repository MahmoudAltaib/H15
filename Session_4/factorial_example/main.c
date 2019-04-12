#include <stdio.h>
#include <stdlib.h>
#include "inttypes.h"

int main()
{
    uint32_t   i32inp = 0;
    uint32_t   i32oup = 1;

    scanf("%d",&i32inp);
    do
    {
        i32oup *= i32inp;
        i32inp--;
    }
    while(i32inp > 0);

    printf("result=%d",i32oup);

    return 0;
}
