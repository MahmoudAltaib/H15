#include <stdio.h>
#include <stdlib.h>

int Add(int a, int b);
int Add(int a, int b)
{

    return a+b;
}

int main()
{

    int(*pf)(int x,int y)=0;
    int q=0;
    pf=Add;
    q=pf(8,2);
    printf("%d",q);
    return 0;
}
