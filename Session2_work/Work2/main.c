#include <stdio.h>
#include <stdlib.h>

int main()
{
   float x = 5.001;
   printf("%f \n",x);
   if (x==4.999f+0.002f)
   {
       printf("Correct \n");
   }
   else
    {
       printf("Wrong \n");
    }
}
