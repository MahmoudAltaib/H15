#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main()
{
    uint8_t u8Bit=0;
    uint8_t u8Cnt=0;
    while (u8Cnt<5)
    {
        u8Bit |= (1<<2);
        printf("%d\n",u8Bit);
        u8Bit &= ~(1<<2);
        printf("%d\n",u8Bit);
        u8Cnt++;
    }

    return 0;
}
