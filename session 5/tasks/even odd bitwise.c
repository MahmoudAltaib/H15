#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number = 0;
    printf("enter the number \n");
    scanf("%d" , &number);

    if(number & 1)
    {
        printf("The number is odd");
    }
    else
    {
        printf("The number is even");
    }
    return 0;
}
