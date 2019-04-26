#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>



int main()
{
    int i32data=0;
int *pi32Ref=0;
    pi32Ref=&i32data;
    *pi32Ref=10;
    printf("%d\n",i32data);
    printf("%d",*pi32Ref);
    return 0;
}
