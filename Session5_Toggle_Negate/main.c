#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main()
{

    uint8_t u8Bit = 0;
    uint8_t u8Cnt = 0;

    for(u8Cnt = 0; u8Cnt <= 10; u8Cnt++)
    {
    u8Bit = ~u8Bit;
    u8Bit &= (1<<2);

    printf("%d\n",u8Bit);
    }

    return 0;
}
