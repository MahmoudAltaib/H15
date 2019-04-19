#include <stdio.h>
#include <stdlib.h>

int main()
{
    float FirstNumber = 0;
    float SecondNumber = 0;
    printf("please enter the first number\n");
    scanf("%f" , &FirstNumber);
    printf("please enter thesecond number\n");
    scanf("%f" , &SecondNumber);
    FirstNumber = FirstNumber + SecondNumber ;
    SecondNumber = FirstNumber - SecondNumber ;
    FirstNumber = FirstNumber - SecondNumber ;
    printf("First number = %f \n" , FirstNumber);
    printf("Second number = %f \n" , SecondNumber);


    return 0;
}
