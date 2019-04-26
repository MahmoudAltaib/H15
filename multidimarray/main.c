#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
 char str1[10]="1 2 3";
 char str2[10]="4 5 6";
 char str3[20]={0};
 int k=0;
for (int i=0;str1[i]!='\0';i++)
{
    str3[i]=str1[i];
    k=i;
}
for(int j=0;str2[j]!='\0';j++)
{
    str3[k+1]=str2[j];
    k++;
}
printf("%s\n",str3);

 return 0;
 }


