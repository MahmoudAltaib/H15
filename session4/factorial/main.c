#include <stdio.h>
#include <stdlib.h>
#include "inttypes.h"
int main()
{


uint32_t    u32IN=0;
uint32_t    u32RES=1;
scanf("%d",&u32IN);
do
{
    u32RES*=u32IN;
    u32IN--;

} while(u32IN>0);
    printf("RESULT=%u\n",u32RES);

return 0;
}


