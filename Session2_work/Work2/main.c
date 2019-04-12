#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main()
{

  uint32_t i8Fact = 1;
  int32_t i8Num1 = 1;
  int8_t i8Count = 1;

  printf("Enter a number  :   ");
  scanf("%d",&i8Num1);

  for(i8Count = 1; i8Count <= i8Num1 ; i8Count++)
  {
      i8Fact = i8Fact * i8Count ;
  }

    printf("The factorial of %d is %u \n",i8Num1,i8Fact);
}
