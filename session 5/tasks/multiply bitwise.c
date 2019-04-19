#include <stdio.h>
#include <stdlib.h>

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

    while(y != 0)
    {
    if(y & 1)
    {
        result += x ;
    }
    x = x << 1 ;
    y = y >> 1 ;
    }
    return result;
}
