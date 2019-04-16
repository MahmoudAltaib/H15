#include <stdio.h>
#include <stdlib.h>
#include<inttypes.h>

int main()
{
    uint8_t u8Num=0;
    uint8_t u8Rem=0;
    printf("please enter a number=%d\n");
    scanf("%d,&u8Num");
    u8Rem=u8Num%2;
    if(u8Rem==1)
    {
        printf("%d is odd\n",u32Num);
    }
    else if(u8Rem==0)
    {
        printf("%d is Even\n",u32Num);
    }
    return 0;


}
