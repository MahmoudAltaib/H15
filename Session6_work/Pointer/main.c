#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main()
{
    int32_t u32Var = 0;
    int32_t *pu32Var = 0;

    pu32Var = &u32Var;

    *pu32Var = 15 ;

   printf("%d\n",*pu32Var);

   (*pu32Var)++;

   printf("%d\n",*pu32Var);


return 0;
}
