#include <stdio.h>
#include <stdlib.h>

int Add (int A , int B);


int main()
{
    int x = 5 , y = 4 , R = 0;

    int (*Ptf)(int x , int y) = Add;
    R = Ptf(x,y);

    printf("%d\n",R);
    printf("%d\n",*Ptf);


    return 0;
}
int Add(int A , int B)
{
    return A+B ;
}
