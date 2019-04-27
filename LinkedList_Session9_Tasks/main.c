#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "string.h"
#include "Searching.h"
#include "Stack_m.h"

int main()
{

Node *pElement = 0;

pElement = (Node*) malloc(sizeof(Node));

if(pElement == 0)
{
  printf("Error\n");
}

else
{

pElement -> x = 50;

strncpy(pElement -> szName, "Mouhanad Mansour", STR_LEN);

if(CreateList(pElement))
{
    PrintList();
}
else
{
  printf("Error\n");
}

free(pElement);
pElement = 0;
pElement = (Node*) malloc(sizeof(Node));
if(pElement == 0)
{
  printf("Error\n");
}

else
{
    pElement -> x = 100;
    strncpy(pElement -> szName, "Ahmed Moustafa", STR_LEN);
    if(addHead(pElement))
    {
        PrintList();
    }
}
free(pElement);
pElement = 0;
pElement = (Node*) malloc(sizeof(Node));
if(pElement == 0)
{
  printf("Error\n");
}

else
{
pElement -> x = 150;
strncpy(pElement -> szName, "Mahmoud Mohamed", STR_LEN);

    if(addTail(pElement))
    {
        PrintList();
    }

}

int test = 0;
LL_getSize(&test);
printf("%d\n",test);


free(pElement);
pElement = 0;
pElement = (Node*) malloc(sizeof(Node));
if(pElement == 0)
{
  printf("Error\n");
}

else
{
    pElement -> x = 500;
    strncpy(pElement -> szName, "Ahmed Hammam", STR_LEN);
    if(index_insert(1,pElement))
    {
        PrintList();
    }
}

}

free(pElement);
pElement = 0;
pElement = (Node*) malloc(sizeof(Node));
if(pElement == 0)
{
  printf("Error\n");
}

else
{
    pElement -> x = 700;
    strncpy(pElement -> szName, "Alaa Moustafa", STR_LEN);
    if(stack_push(pElement))
    {
        PrintList();
    }
    Node popped = {0};
    if(stack_pop(&popped))
    {
        PrintList();
    }

}


int arr[7]={1,5,10,15,7,1,3,2};
int *pArray = arr;
int index = 0;
int n_duplications = 0;
LinearSearch(7,7,pArray,&index);
Is_Duplicated(1,7,pArray,&n_duplications);
printf("%d\n",index);
printf("%d",n_duplications);
return 0;
}

