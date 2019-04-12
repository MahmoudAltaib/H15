#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x=0;
    printf("Grade= ");
    scanf("%d",&x);
    switch (x)
    {
    case 0 ... 50 :
        printf("Bad");
        break;
    case 51 ... 75 :
        printf("Good");
        break;
    case 76 ... 85 :
        printf("Very Good");
        break;
    case 86 ... 100 :
        printf("Excellent");
        break;
    default :
        printf("Invalid");
    }

    return 0;
}
