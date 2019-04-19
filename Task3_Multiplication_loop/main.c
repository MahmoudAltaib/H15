#include <stdio.h>
#include <stdlib.h>
int Mult(int First_num, int Second_num);
int main()
{
    int First_num = 0;
    int Second_num = 0;

    printf("Enter the First Number:\n");
    scanf("%d",&First_num);
    printf("Enter the Second Number:\n");
    scanf("%d",&Second_num);


     printf("Result is: %d\n",Mult(First_num,Second_num));


    return 0;
}

int Mult(int First_num, int Second_num)
{
    int i = 0;
    int Temp = 0;

 if(First_num < Second_num)
    {
        Temp = Second_num;
      for (i=2; i<=First_num; i++)
      {
          Second_num += Temp;
      }
      return Second_num;
    }
    else
    {
        Temp = First_num;
      for (i=2;i<=Second_num;i++)
      {
       First_num += Temp;
      }
      return First_num;
    }

}
