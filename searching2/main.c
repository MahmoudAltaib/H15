#include <stdio.h>
#include <stdlib.h>

int search_doubled (int y[]);
int search_doubled (int y[])
{

     int i=0 ;
     int j=0;
    for (i=0;i<7;i++)

        for(j=i+1;j<7;j++)
if ((y[i])==(y[j]))

{
    printf(" Numeber %d is doubled ", y[i]);

}





        else
        {

        }
return 0 ;
}

int main()
{

    int y[7]={1,5,10,15,7,7,1};
     search_doubled (y);


    return 0;
}
