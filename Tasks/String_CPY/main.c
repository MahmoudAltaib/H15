#include <stdio.h>
#include <stdlib.h>

int main()
{
    char  S3[50] , i;

   char S1[50]= "Hello \0";
    printf("%s \n",S1);


   for(i=0;S1[i]!='\0';i++)
   {
           S3[i]=S1[i];

    }

S3[i]='\0';
       printf("%s",S3);

    return 0;
}
