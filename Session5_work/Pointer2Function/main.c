#include <stdio.h>
#include <stdlib.h>

int add(int,int);

int main()
{
  int z = 0;
  int (*pfAdd)(int x, int y) = 0 ;

  pfAdd = &add;

  z = pfAdd(3,4);

  printf("z = %d",z);
}


int add(int a, int b)
{
    return a+b;
}
