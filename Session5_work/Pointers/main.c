#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main()
{
    uint8_t u8Num = 5;
    uint8_t u8Num1 = 10;
    uint8_t *Pointer_to_Num = &u8Num;

    printf("Num = %d      \n",u8Num);
    printf("Num address = %d      \n",&u8Num);

    printf("Pointer value = %d   \n",*Pointer_to_Num);
    printf("Pointer value = %d   \n",Pointer_to_Num);
    printf("Pointer address = %d   \n",&Pointer_to_Num);

    *Pointer_to_Num ++ ;

 printf("Pointer value = %d   \n",*Pointer_to_Num);
    printf("Pointer value = %d   \n",Pointer_to_Num);
    printf("Pointer address = %d   \n",&Pointer_to_Num);


    return 0;
}
