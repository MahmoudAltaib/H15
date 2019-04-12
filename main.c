#include <stdio.h>
#include <stdlib.h>
#include "inttypes.h"
int main()
{
    /*int8_t grade = 0;
    int8_t y = 0;
    int8_t z = 0;

    printf("Please Enter The Value Of x below: \n");
    scanf("%d",&x);
    printf("Please Enter The Value Of y below: \n");
    scanf("%d",&y);

    z = x+y;

    printf("z = %03d",z);*/
   /* switch(grade)
    {
        case 50: printf("5");
        case 6: printf("6"); break;
        default: 0;
    }*/
    /*if(printf("Ahmed"))
    {

    }*/

    //for(;;) // This is the infinite loop in C
    int8_t i8Cnt;
    for(i8Cnt = 1; i8Cnt<=10 ; i8Cnt++) // i8Cnt is used just for the naming convention to reach a clean code.
    {
       printf("%d\n", i8Cnt);

    }
    return 0;
}
