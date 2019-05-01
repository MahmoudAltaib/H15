#include <stdio.h>
#include <stdlib.h>

int search (int *y,int *j);
int search (int *y,int *j)
{

     int i=0 ;
    for (i=0;i<7;i++)
        if (*(y + i)==7)
        {
            printf("%d\n",i);
            return 1 ;
        }
        else
        {

        }
return 0 ;
}

int main()
{

    int y[7]={1,5,10,15,7,3,2};
    int index = 0;
     search (y,&index);


    return 0;
}
