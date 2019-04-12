#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x=5.001;

    if(x==5.001F)   //we must write f after the value because of rounding the if will convert the variable type to integer
    {
        printf("correct\n");
    }
    else
    {
        printf("wrong\n");
    }
    return 0;
}
