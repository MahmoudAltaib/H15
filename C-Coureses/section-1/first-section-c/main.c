#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
   float y;
   double z;
   char g;
   x = sizeof(int);
   y = sizeof(float);
   z = sizeof(double);
   printf("size of int = %d\n",x);
   printf("size of float = %f\n",y);
   printf("size of double = %d\n",z);
   return 0;


   int x = 0;
   int y = 0;
   int z = 0;
   printf("Enter x: \n");
   scanf("%d",&x);
   printf("Enter y: \n");
   scanf("%d",&y);
   z = x+y;
   printf("z=%d\n",z);
    return 0;
}
