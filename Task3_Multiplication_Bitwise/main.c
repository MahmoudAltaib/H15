#include <stdio.h>
#include <stdlib.h>
int Mult(int First_num,int Second_num);
int main()
{
    int First_num = 0;
    int Second_num = 0;
    printf("Enter the First Number:\n");
    scanf("%d",&First_num);
    printf("Enter the Second Number:\n");
    scanf("%d",&Second_num);

      printf("Result is: %d",Mult(First_num,Second_num));


    return 0;
}

int Mult(int First_num,int Second_num)

{
    int result = 0;
    int counter = 0;

    if(First_num < Second_num)
    {
      while (First_num)
      {
          if (First_num % 2 == 1)
          {
            result+=Second_num<<counter;
          }
          counter++;
          First_num/=2;
      }
      return result;
    }
    else
    {
      while (Second_num)
      {
          if (Second_num % 2 == 1)
          {
            result+=First_num<<counter;
          }
          counter++;
          Second_num/=2;
      }
      return result;
    }



}
