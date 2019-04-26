#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char S[50] , i ;
    int length = 0 ;


    printf("Enter String \n");
    scanf("%s",S);

    for(i=0;S[i]!='\0';i++)
    {
        length++;
    }

    printf("Length =%d",length);
    return 0;
}
