#include <stdio.h>
#include <stdlib.h>

int main()
{
    char S1[50] , S2[50] , S3[50] ;
    int i=0 , j=0 ;

    printf("Please Enter S1 \n");
    scanf("%s",S1);

    printf("Please Enter S2 \n");
    scanf("%s",S2);

    while(S1[i]!='\0')
    {
        S3[i]=S1[i];
        i++;

    }
    while (S2[j]!='\0')
    {
        S3[i]=S2[j];
        i++;
        j++;
    }
    S3[i]='\0';

    printf("%s",S3);

    return 0;

}
