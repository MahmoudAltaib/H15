#include "ListProject.h"
#include "string.h"
#include "stdlib.h"
#include <stdio.h>
static Node *pHead = 0;

extern uint8_t createList(Node *n)
{

    if(pHead != 0)
    {
        return 0;
    }

    else
    {
        pHead = (Node*) malloc(sizeof(Node));

        if(pHead == 0)
        {
            return 0;
        }
        else
        {
            memcpy(pHead, n, sizeof(Node));
            pHead -> pNext = 0;
            return 1;
        }
    }
}

extern uint8_t addHead(Node *pElement)
{
    Node *pTemp = 0;
    if(pElement == 0)
    {
        return 0;
    }

    if(pHead == 0)
    {
        if(createList(pElement) == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
       pTemp = (Node*) malloc(sizeof(Node));
       if(pTemp == 0)
       {
           return 0;
       }
       else
       {
           memcpy(pTemp, pElement, sizeof(Node));
           pTemp -> pNext = pHead;
           pHead = pTemp;
           return 1;
       }
    }
}

extern uint8_t addTail(Node *pElement)
{
    Node *pTemp = 0;
    Node *pMove = 0;

    if(pElement == 0)
    {
        return 0;
    }

    if(pHead == 0)
    {
        if(createList(pElement) == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
       pTemp = (Node*) malloc(sizeof(Node));
       if(pTemp == 0)
       {
           return 0;
       }
       else
       {
           memcpy(pTemp, pElement, sizeof(Node));
           pMove = pHead;
           while(pMove -> pNext != 0)
           {
               pMove = pMove -> pNext;
           }
           pMove -> pNext = pTemp;
           pMove -> pNext -> pNext = 0;
           return 1;
       }
    }
}

extern void printmembers(void)
{
    Node *pMove = 0;
    uint8_t cnt = 0;
    if(pHead == 0)
    {
        printf("The Linked List Has 0 Member\n");
        return;
    }
    pMove = pHead;
    while(pMove != 0)
    {
        printf("Member Number : %d \n"\
                "Member Value = %d \n"\
                "Member ID=%d \n" \
                "Member Name : %s \n", cnt, pMove -> degree,pMove -> ID, pMove -> stName);
        pMove = pMove -> pNext;
        cnt++;
    }

}



