#include <stdio.h>
#include <stdlib.h>
#include "add.h"



void main(void)
{
    int x = 5;
    int y = 2;
    int z = 0;
    int * shosha = &x;
    int * shoshay = &y;
    int **shosha2shosha = &shosha;
    printf("enter value!\n");
    scanf("%d%d",&x,&y);
    //z = sum(x,y);
    printf("%d",z);
    printf("%d\n%d\n%d\n%d\n",shosha,&shosha,*shosha,&x);
    /*sum(shosha,shoshay);
    printf("%d\n",*shosha);
    printf("%d\n",*(*shosha2shosha));
    printf("%d\n",*(&x));
    z = (x<y)? 5:10;
    printf("%d",z);*/

}


