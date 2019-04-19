#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main()
{

   uint64_t number = 0;
   uint64_t result=0;
    printf("please enter the number \n");
    scanf("%d" , &number);

result = number ;
    for(number= number -1 ; number >0; number--)
    {
        result = result * number ;

    }
    printf("the result is % \n", result);
    return 0;
}
