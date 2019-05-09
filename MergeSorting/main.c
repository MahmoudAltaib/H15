#include <stdio.h>
#include <stdlib.h>
extern void swap(int*x,int*y)
{
    int temp=*x;
    *x=*y;
    *y=temp;

}
    extern void print(void)
{
    int a[4];
    int b[4];
    printf("%d\n", a[4]);
    printf("%d\n", b[4]);
}


int main()
{
    int x[8]={7,6,5,4,3,2,1,0};
    int min=0;
    int i=0;
    int j=0;
    int a[4]={x[0],x[1],x[2],x[3]};
    for (i=0;i<7;i++)
{
       min = i;

    for (j=i+1;j<7;j++)
    {



        if (x[j]< x[i])
        {
            min = j;

swap(&a[min],&a[i]);
        }
    }
}
int b[4]={x[4],x[5],x[6],x[7]};

for (i=0;i<7;i++)
{
       min = i;

    for (j=i+1;j<7;j++)
    {



        if (x[j]< x[i])
        {
            min = j;

swap(&b[min],&b[i]);
        }
    }
}

    return 0;

}



