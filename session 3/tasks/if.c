#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x = 0;
    printf("please enter your grade: \n");
    scanf("%f" , &x);
    if(x <= 50 && x >=0 )
    {
        printf("fail\n");
    }
    else
    {
        if(50 < x && x <= 60)
        {
             printf("pass\n");
        }
        else
        {
            if(60 < x && x <= 70)
            {
                 printf("good\n");
            }
            else{
                if(70 < x && x <=80)
                {
                     printf("very good\n");
                }
                else
                {
                    if(80 < x && x <= 100)
                    {
                        printf("excellent\n");
                    }
                    else{
                         printf("wrong entry\n");
                    }
                }

            }
        }
    }
    return 0;
}
