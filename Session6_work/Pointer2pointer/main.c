#include <stdio.h>
#include <stdlib.h>
#include<inttypes.h>

int main()
{
   int i32Data = 10;
   int **pi32Ref = &i32Data;


   printf("%d\n",i32Data);
   printf("%d\n",pi32Ref);
   printf("%d\n",&pi32Ref);
   printf("%d\n",*pi32Ref);
   printf("%d\n",**pi32Ref);
}
