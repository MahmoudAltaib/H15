#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main()
{
  uint32_t Fac_num = 0;

  uint32_t Cnt = 0;

  printf("Please enter the number:");
  scanf("%d",&Fac_num);

  for(Cnt = Fac_num; Cnt >= 2; Cnt--)
  {
    Fac_num *= Cnt - 1;
  }
  printf("%u",Fac_num);


    return 0;
}
