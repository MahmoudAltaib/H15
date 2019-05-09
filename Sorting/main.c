#include <stdio.h>
#include <stdlib.h>
void swap(int*x,int*y);
void swap(int*x,int*y)
{
    int temp=*x;
    *x=*y;
    *y=temp;

}

int main()
{
    int x[7]={10,5,3,20,21,12,16};
    int min=0;
    int i=0;
    int j=0;

for (i=0;i<7;i++)
{
       min = i;

    for (j=i+1;j<7;j++)
    {



        if (x[j]< x[i])
        {
            min = j;

swap(&x[min],&x[i]);

        }
    }

}


for (i=0;i<7;i++)
{
 printf("%d\n",x[i]);
}



    return 0;
}

