#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number = 0;
    printf("enter the number \n");
    scanf("%d" , &number);

    if(number % 2 ==0)
    {
        printf("The number is even");
    }
    else
    {
        printf("The number is odd");
    }
    return 0;
}
