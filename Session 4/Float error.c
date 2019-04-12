#include <stdio.h>
#include <stdlib.h>

int main()
{float x=5.001;
if (x==5.001f) /*adding f after the number in order to avoid rounding*/
{
    printf("correct\n");
}
else
{
    printf("wrong\n");
}
    return 0;
}
