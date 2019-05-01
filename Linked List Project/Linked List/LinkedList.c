#include "LinkedList.h"
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

extern uint8_t deleteHead()
{
    Node *pMove = pHead;

    if(pHead == 0)
    {
        printf("Cannot Delete From An Empty Linked List\n");
        return 0;
    }
    else
    {
        pHead = pHead -> pNext;
        free(pMove);
        pMove = 0;
        printf("Head Deleted\n");
        return 1;
    }
}

extern uint8_t deleteTail()
{
    Node *pMove = pHead;

    if(pHead == 0)
    {
        printf("Cannot Delete From An Empty Linked List\n");
        return 0;
    }
    else
    {
        if(pHead -> pNext == 0)
        {
            deleteHead();
        }
        while(pMove -> pNext -> pNext != 0)
        {
            pMove = pMove -> pNext;
        }

        pMove -> pNext = 0;
        free(pMove);
        pMove = 0;
        printf("Tail Deleted\n");
        return 1;
    }
}




extern uint8_t addElementByIndex(Node *pElement, uint8_t index)
{
    Node *pMove = pHead;
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
        uint8_t cnt = 0;
        pTemp = (Node*) malloc(sizeof(Node));

        if(pTemp == 0)
        {
            return 0;
        }
        else
        {

            pMove = pHead;

            while(pMove != 0)
            {
                if(cnt == index - 1)
                {
                    pMove -> pNext = pTemp;
                    pTemp = pTemp -> pNext;
                    printf("DONE");
                }
                else
                {
                    cnt++;
                    pMove = pMove -> pNext;
                }
            }

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



