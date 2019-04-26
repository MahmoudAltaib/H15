#include <stdio.h>
#include <stdlib.h>

int main()
{
    char S1[50] , S2[50] ;
    int i=0 , j=0 , x=0 , y=0 ;

    printf("Please Enter S1 \n");
    scanf("%s",S1);

    printf("Please Enter S2 \n");
    scanf("%s",S2);


    for(i=0;S1[i]!='\0';i++)
    {
        x++;
    }


    for(j=0;S2[j]!='\0';j++)
    {
        y++;
    }

    if(x>y)
    {
        printf("+Ve");
    }
    else
        printf("-Ve");



    return 0;
}
