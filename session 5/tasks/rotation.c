#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 0 ;
    int rotation = 0 ;
    int RotatedNumber = 0  ;
    printf("enter the number to be rotated : \n");
    scanf("%d" , &num);
    printf("enter the number of rotations : \n");
    scanf("%d" , &rotation);

          printf("%d \n" , rotate(num , rotation) );
    return 0;
}

int rotate (int n , int r)
{
    int size = (sizeof(int) * 8) - 1 ;
    while(r > 0)
    {
      if(n & 1)
      {
          n = n >> 1 ;
          n = n | (1 << size) ;
      }
        else
        {
            n = n >> 1 ;
        }
        r--;
    }
    return n;
}
