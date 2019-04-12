#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x=0;

    printf("Enter Student Degree =\n");
    scanf("%d",&x);

    if (x<50)
    {
        printf("Fail\n");
    }
    else if ((x>=50)&&(x<=60))
    {
        printf("Pass\n");
    }
    else if ((x>60)&&(x<=70))
    {
        printf("Good\n");
    }
    else if((x>70)&&(x<=80))
    {
        printf("very good\n");
    }
    else if((x>80)&&(x<=100))
    {
        printf("Excellent\n");
    }
    else
    {
        printf("Error\n");
    }
    return 0;
}
