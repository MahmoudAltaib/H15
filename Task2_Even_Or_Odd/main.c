#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>

int main()
{
    int32_t i32Num = 0;

    printf("Enter the number:\n");
    scanf("%d",&i32Num);
    if(i32Num % 2 == 0)
    {
       printf("The number is even");
    }
    else{
      printf("The number is odd");
    }
    return 0;
}
