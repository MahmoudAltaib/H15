#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main()
{
    int32_t i32Var = 0;
    int32_t *pi32Var = 0;

    pi32Var = &i32Var;

    *pi32Var = 15 ;

   printf("%d\n",*pi32Var);

   (*pi32Var)++;

   printf("%d\n",*pi32Var);


return 0;
}


