#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i , j , k ;

    int arr[2][3] = {0};
    int **pvar = 0 ;



    for(i=0 , k=0 ; i<2 ; i++)
    {


        for(j=0;j<3;j++)
        {


        *((*(pvar+i))+j) = k++;
        }
 printf("%d\n",arr[0][0]);
    printf("%d\n",arr[0][1]);
    printf("%d\n",arr[0][2]);
    printf("%d\n",arr[1][0]);
    printf("%d\n",arr[1][1]);
    printf("%d\n",arr[1][2]);

        }
    return 0;
}
