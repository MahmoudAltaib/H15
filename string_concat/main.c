#include <stdio.h>



int main()
{
   int i,j;
   int k=0;
   int arr[2][3]={0};
   int(*parr)[3]=arr;
   for(i=0;i<2;i++)
    for(j=0;j<3;j++)
   {
       (*(*(parr+i)+j))=k;
       k++;
   }
 for(i=0;i<2;i++)
 {

    for(j=0;j<3;j++)
        printf("%d %d \n",arr[i][j],(*(*parr+i)+j));
    return 0;
 }
}


