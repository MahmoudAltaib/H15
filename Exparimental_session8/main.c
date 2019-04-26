#include <stdio.h>
#include <stdlib.h>


   typedef union
   {

       int i;

   char string[8];

   }y;
y w;
   int main()
{
w.i=10;
w.string[0]=5;
printf("%d",w.i);
    return 0;
}
