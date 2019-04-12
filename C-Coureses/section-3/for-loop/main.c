#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
int main()
{
    /*
     int8_t  i6Count = 0;
        for(i6Count = 1; i6Count <= 10; i6Count++)
        {
            printf("%d\n",i6Count);
        }
    */
    float y = 5.001;
    if(y == 5.001F)
    {
        printf("correct\n");
    }
    else
    {
        printf("wrong\n");
    }
    return 0;
}
