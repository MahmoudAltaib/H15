#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main()
{
   int a = 0  ;
   int b = 0 ;
   int multiplication = 0 ;

    printf("enter the first number : \n");
    scanf("%d" , &a);
    printf("enter the second number : \n");
    scanf("%d" , &b);

    multiplication = multiply(a , b);
    printf("the multiplication of the two numbers = %d" ,multiplication);
    return 0;
}

int multiply (int x , int y)
{
    int result = 0;
    int i = 0;
    while(i < y)
    {
        result += x;
        i++;
    }
    return result;
}
