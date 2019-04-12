#include <stdio.h>
#include <stdlib.h>

int main()
{int x=0;

printf("grade:");
    scanf("%d",&x);
    if (x>=0 && x<50)
    {
      printf("Bad");
    }
    else if (x>=50 && x<75)
    {
        printf("Good");
    }
    else if (x>=75 && x<85)
    {
        printf("very Good");
    }
    else if (x>=85 && x<=100)
    {
        printf("Excellent");
    }
    else
    {
        printf("invalid");
    }

    return 0;
}
