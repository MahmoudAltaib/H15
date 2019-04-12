#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x=5.001;
    if(x==5.001f)
    {
        printf("correction\n");
    }
    else
    {
        printf("wrong\n");
    }
    return 0;
}
