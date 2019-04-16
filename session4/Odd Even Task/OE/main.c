#include <stdio.h>
#include <stdlib.h>
#include<inttypes.h>

int main()
{
 const volatile int iRes=1;
 scanf("%d",&iRes);
 if(iRes==1)
 {
     printf("correct\n");
 }
 else
 {
    printf("wrong\n");

 }

 return 0;
}


