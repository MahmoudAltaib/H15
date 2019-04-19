#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main()
{
    uint8_t u8Bit=0;
    u8Bit |= (1<<3); //set Bit
    u8Bit &= ~(1<<3); //clear bit
    u8Bit ^= (1<<3); //toggle bit with XOR

    return 0;
}
