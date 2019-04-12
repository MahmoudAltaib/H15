#include "stdio.h"
#include <stdio.h>
#include "inttypes.h"
int main()
{
int32_t i32inp = 0;
int32_t i32res = 0;

printf("enter number:=");
scanf("%d",&i32inp);
i32res=i32inp%2;
while(i32res==0)
{
printf("\neven ");
break;
}
while ( i32res != 0)
{
printf("\n odd ");
break;
}
return 0;
}

