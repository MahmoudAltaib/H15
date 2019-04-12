#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
   float Grade=0;
   printf("Enter the score:\n");
   scanf("%f",&Grade);
   // ********** Conditional if **********
   if(Grade>=0 && Grade<=50)
   {
       printf("Your Grade is \"Fail\"\n");
   }
   else if(Grade>50 && Grade<=60)
   {
       printf("Your Grade is \"Pass\"\n");
   }
   else if(Grade>60 && Grade<=70)
   {
       printf("Your Grade is \"Good\"\n");
   }
   else if(Grade>70 && Grade<=80)
   {
       printf("Your Grade is \"Very Good\"\n");
   }
  else if(Grade>80 && Grade<=100)
   {
       printf("Your Grade is \"Excellent\"\n");
   }
   else
   {
       printf("This is not a valid score\n");
   }

   // ********** Switch **********

switch((int) ceil(Grade/10))
{
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        printf("Your Grade is \"Fail\"");
        break;


    case 6:
        printf("Your Grade is \"Pass\"");
        break;

    case 7:
        printf("Your Grade is \"Good\"");
        break;

    case 8:
        printf("Your Grade is \"Very Good\"");
        break;

    case  9:
    case 10:
        printf("Your Grade is \"Excellent\"");
        break;

    default:
        printf("This is not a valid score");
        break;
}


    return 0;
}
