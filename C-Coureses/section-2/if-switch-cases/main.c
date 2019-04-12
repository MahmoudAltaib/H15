#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    int number;
    printf("Enter an integer: ");
    scanf("%d",&number);

    if( number <= 50)
    {
        printf("%d Unacceptable.",number);
    }
    else if(number <= 60)
    {
        printf("%d fair.",number);
    }
    else if(number >= 70)
    {
        printf("%d Good.",number);
    }
    else if(number >= 80)
    {
        printf("%d Very good.",number);
    }
        else if(number >= 90)
    {
        printf("%d Excellent.",number);
    }
    */
    int number;
    printf("Enter number: ");
    scanf("%d",&number);

    switch(number) {
   case 0 ... 49  :
      printf("%d Unacceptable.",number);
      break; /* optional */

   case 50 ... 59  :
      printf("%d fair.",number);
      break; /* optiona2 */

   case 60 ... 69  :
      printf("%d Good.",number);
      break; /* optiona3 */

   case 70 ... 79  :
      printf("%d Very good.",number);
      break; /* optiona4 */

   case 80 ... 100  :
       printf("%d Excellent.",number);
      break; /* optiona5 */
    }
    return 0;
}
