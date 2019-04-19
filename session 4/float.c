#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main()
{

    float x = 5.001 ;
    if(x == 5.001f)
    {
        printf("correct \n");
    }
    else
    {
       printf("wrong \n");
    }
    return 0;
}
