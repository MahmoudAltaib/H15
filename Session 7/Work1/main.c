#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

uint32_t u32Fact(uint32_t u32Num);

int main()
{
    uint32_t u32Result = 0;

    u32Result = u32Fact(5);

    printf("The result is    %d",u32Result);

   return 0 ;
}

uint32_t u32Fact(uint32_t u32Num)
{

    if(u32Num == 1)
    {
        return 1;
    }

    return u32Num*u32Fact(u32Num - 1);
}
