#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main()
{
    int32_t i32First = 0;
    int32_t i32Second = 0;

    printf("Enter The first number:\n");
    scanf("%d",&i32First);
    printf("Enter The second number:\n");
    scanf("%d",&i32Second);

    i32First = i32First + i32Second;
    i32Second = i32First - i32Second;
    i32First = i32First - i32Second;


printf("The first number became:%d\n",i32First);
printf("The second number became:%d\n",i32Second);
    return 0;
}
