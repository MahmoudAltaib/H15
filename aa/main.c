#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int x = 10 ;
    int *ptr = &x ;

    printf("%d",x);

    *ptr = 5 ;
    printf("%d",x);

}
