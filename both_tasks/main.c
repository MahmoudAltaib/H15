#include <stdio.h>
#include <stdlib.h>

int main()

{
    float Grade=0;
    printf("Enter Grade:\n");
    scanf("%f",&Grade);

        if ((Grade>=0)&&(Grade<50))
         {
           printf("Fail:\n");
         }
        else if((Grade>=50)&&(Grade<=60))
          {
           printf("Pass:\n");
          }
        else if((Grade>60)&&(Grade<=70))
        {
            printf("Good:\n");
        }
       else if((Grade>70)&&(Grade<=80))
       {
            printf("VeryGood:\n");
       }
        else if((Grade>85)&&(Grade<=100))
        {
            printf("Excellent:\n");
        }

    return 0;
}
