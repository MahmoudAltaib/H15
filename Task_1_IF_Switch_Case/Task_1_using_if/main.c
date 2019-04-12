#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 0;

printf("hello enter x:");
    scanf("%d",&x);
     if(x<=50)
     {
         printf("Fail");
     }
else if(x<=60)
{
    printf("pass");
}
else if(x<=70)
{
    printf("Good");
}
else if(x<=80)
{
    printf("Very Good");
}
else if(x<=100)
{
    printf("Perfect");
}
else
{
    printf("error");
}
    return 0;
}
