#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define DEBUG

int main()
{
    uint32_t u32Num1 = 0;
    uint32_t u32Num2 = 0;

    u32Num2=scanf("%d",&u32Num1);

    #ifdef DEBUG
    if (u32Num2 == 0)
    {
        printf("Error \n");
        return 0;
    }
    #endif // DEBUG

    printf("The value of Num1 is %d",u32Num1);

   return 0;
}
