#include <stdio.h>
#include <stdlib.h>
#include"inttypes.h"

int Fact(uint64_t Var);
int main()
{
    uint64_t X = 0 ;
    uint64_t Var = 0;

scanf("%d",&Var);
X = Fact(Var);


printf("This is R =%d\n",X);


}


int Fact(uint64_t Var)
{


    if(Var == 1)
        return 1;

    return Var * Fact(Var-1);


}
