#include <stdio.h>
#include <stdlib.h>

int main()
{
    float FirstNumber = 0;
    float SecondNumber = 0;
    float x = 0;
    printf("please enter the first number\n");
    scanf("%f" , &FirstNumber);
    printf("please enter thesecond number\n");
    scanf("%f" , &SecondNumber);
    x = FirstNumber ;
    FirstNumber = SecondNumber ;
    SecondNumber = x ;
    printf("First number = %f \n" , FirstNumber);
    printf("Second number = %f \n" , SecondNumber);


    return 0;
}
