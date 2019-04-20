#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define MODE 3

int main()
{
    uint32_t u32Num1 = 0;

    #if (MODE == 1)
    printf("Num1 in mode 1=  %d",++u32Num1);
    #elif (MODE ==2)
     printf("Num1 in mode 1=  %d",u32Num1+=2);
    #elif (MODE ==3)
     printf("Num1 in mode 1=  %d",u32Num1+=3);
    #endif
}
