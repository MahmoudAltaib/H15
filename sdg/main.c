#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 0 ;
    int *p = &x ;
    printf("%d , %d " , x , *p);

    *p = 5 ;

    *(p) = 6 ;

    printf("%d" , x);


}
