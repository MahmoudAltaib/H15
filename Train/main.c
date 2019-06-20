#include <stdio.h>
#include <stdlib.h>
int swap (int X,int Y,int temp);

int swap(int X,int Y,int temp)
{

 temp= X;
X= Y;
 Y=temp;
 printf("%d\n",X);
        printf("%d\n",Y);
}


int main()
{
    int res=0;
    int a=0;int b=0;int temp2=0;
    printf("enter first number=");
    scanf("%d",&a);
    printf("enter second number=");
    scanf("%d",&b);
    res=swap(a,b,temp2);


    return 0;
}

