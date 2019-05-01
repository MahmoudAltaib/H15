#include "mm.h"
#include "string.h"
#include "stdlib.h"
#include <stdio.h>
static Node *pHead = 0; // static makes the global variable accessible inside this file only. No one will be able to make it extern.

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
            memcpy(pHead, n, sizeof(Node)); // memcpy(dst, src, size)
            pHead -> pNext = 0;
            return 1;
        }
    }
}

extern uint8_t addHead(Node *pElement) // insert first
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
           memcpy(pTemp, pElement, sizeof(Node)); // CREATING A TEMP MEMORY TO BE INSERTED AT FIRST
           pTemp -> pNext = pHead; // POINTER OF TEMP MEMORY POINTS TO THE OLD HEAD
           pHead = pTemp; // MOVE THE HEAD POINTER TO POINT TO THE NEW MEMORY
           return 1;
       }
    }
}

extern uint8_t addTail(Node *pElement)
{
    Node *pTemp = 0; // INSERT LAST
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
           memcpy(pTemp, pElement, sizeof(Node)); // CREATING A TEMP MEMORY TO BE INSERTED AT LAST
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

extern void printList(void)
{
    Node *pMove = 0;
    uint8_t cnt = 0;
    if(pHead == 0)
    {
        printf("Empty Linked List\n");
        return;
    }
    pMove = pHead;
    while(pMove != 0)
    {
        printf("Member Number : %d \n"\
                "Member Value = %d \n"\
                 "Member Name : %s \n", cnt, pMove -> x, pMove -> stName);
        pMove = pMove -> pNext;
        cnt++;
    }

}



