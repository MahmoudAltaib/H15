#include <stdio.h>

#include<inttypes.h>


int swap (int x,int y,int store)
{
    store= x;
     x= y;
     y= store;
     printf("First number after swap=%d\n",x);
     printf("second number after swap=%d\n",y);
}

int main()

{   int a=0;
int Res=0;
    int b=0;
    int store2=0;
    printf("Enter first number\n");
    scanf("%d",& a);
    printf("Enter second number\n");
    scanf("%d",& b);
    Res=swap(a,b, store2);

    return 0;

}
