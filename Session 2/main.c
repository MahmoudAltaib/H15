#include <stdio.h>
#include <stdlib.h>
#include "inttypes.h"
int fact(int var);

int main()
{
    // FACTORIAL USING RECURSION
    unsigned int x = 0;
    printf("please enter the number below\n");
    scanf("%d", &x);
    printf("Result is : %d",fact(x));


    return 0;
}

int fact(int var)
{
    if(var == 1)
    {
        return 1;
    }

    return var * fact(var - 1);
}
