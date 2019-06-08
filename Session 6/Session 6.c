#include <stdio.h>
#include <stdlib.h>
int Add(int A, int B);

int main()
{
    //Pointer to variable//
    int i32Data=15;
    int* pi32Ref=&i32Data;
    printf("%d\n",i32Data);
    printf("%d\n",*pi32Ref);
    printf("%d\n",&i32Data); //end of function 1//

    //Pointer to function//
    int (*Pf)(int x , int y)=0;
    int R=0;
    Pf=Add;
    R=Add(3,1);
    printf("%d\n",R);
    R=0;
    R=Pf(3,1);
    printf("%d",R);
    return 0; //end of function 2//

    //Pointer to Array//
    int arr[10]={0};
    int * pVar=0;
    arr [5]=10;
    pVar=arr; //returns address of first element  in array//
printf("%d",arr);
    pVar=&arr[5];//returns address of 6th element in array//

    *(pVar + 5)=11; //inputs 11 in 6th element in array//
}

int Add(int A, int B)
{



return A+B;
}
