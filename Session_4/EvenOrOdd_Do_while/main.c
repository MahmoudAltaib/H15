#include <stdio.h>
#include <stdlib.h>
#include "inttypes.h"

int main()
{
   int32_t ui32inp = 1 ;
do
{


   printf("Enter an integer\n");
   scanf("%d", &ui32inp );

   if ((ui32inp/2)*2 == ui32inp )
      printf("Even\n");
   else
      printf("Odd\n");

}
while(ui32inp=0);

   return 0;
}
