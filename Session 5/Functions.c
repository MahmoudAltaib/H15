#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main()
{
    const volatile int x=1;
    scanf("%d",&x);
    if(x==1)
    {
        printf("correct");
    }
    else
    {
        printf("wrong");
    }


    return 0;
}
