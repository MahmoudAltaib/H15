#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main()
{
    int32_t i8Cnt = 0;
    int32_t i8Res = 1;

    scanf("%d", &i8Cnt);
    while(i8Cnt > 0)
    {
    i8Res *= i8Cnt;
    i8Cnt--;
    }
        printf("Factorial=%d",i8Res);

    return 0;
}
