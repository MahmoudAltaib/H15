#include <stdio.h>
#include <stdlib.h>
#include"Linked_List.h"

int main()
{
    Node *pElement = 0;

    pElement = (Node * ) malloc(sizeof(Node));

    if(pElement ==0)
    {

        printf("error");
    }
else
{
    pElement -> x =50 ;
    strncpy(pElement -> szName , "Mahmoud Altaib", STR_LEN);

    if(CreateList(pElement)==1)
    {
        printlist();
    }
}
free(pElement);
pElement = (Node * ) malloc(sizeof(Node));
  if(pElement ==0)
    {

        printf("error\n");
    }
    else
    {
        pElement -> x = 100;
        strncpy(pElement -> szName , "Mahmoud A", STR_LEN);

        if(AddHead( pElement)==1)
        {
            printlist();

        }
    }
    free(pElement);
pElement = (Node * ) malloc(sizeof(Node));
  if(pElement ==0)
    {

        printf("error\n");
    }
    else
    {
        pElement -> x = 120;
        strncpy(pElement -> szName , "Mahm", STR_LEN);

        if(AddTail( pElement)==1)
        {
            printlist();

        }
    }

    return 0;
}
