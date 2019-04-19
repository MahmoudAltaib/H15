#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x ;

     printf("please enter your grade: \n");
    scanf("%d" , &x);
    switch(x)
    {
    case 0 ... 49:
        {
        printf("fail\n");
        break;
        }
    case 50 ... 60 :
        {
         printf("pass\n");
         break;
        }
        case 61 ... 70 :
        {
         printf("good\n");
         break;
        }
        case 71 ... 80 :
        {
         printf("very good\n");
         break;
        }
        case 81 ... 100 :
        {
         printf("excellent\n");
         break;
        }
        default :
        {
        printf("wrong entry\n");
        break;
        }
    }

    return 0;
}
