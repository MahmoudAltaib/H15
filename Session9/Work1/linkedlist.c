#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "linkedlist.h"

static Node *pHead = 0;

extern uint8_t Create_list(Node *Head)
{
    if (pHead != 0)
    {
        return 0;
    }
    else
    {
        pHead = (Node *) malloc(sizeof(Node));

        if (pHead == 0)
        {
            return 0;
        }
        else
        {
            memcpy( pHead , Head , sizeof(Node) );
            pHead -> psNext = 0;
            return 1;
        }
    }
}


extern uint8_t addHead (Node *pElement)
{
    Node *pTemp = 0;

    if (pElement == 0)
    {
        return 0;
    }
    else
    {
        if(pHead == 0)
        {
            Create_list(pElement);

            if ((Create_list(pElement)) == 1)
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
            pTemp = (Node *) malloc(sizeof(Node));

            if(pTemp == 0)
            {
                return 0;
            }
            else
            {
                memcpy(pTemp,pElement,sizeof(Node));
                pTemp -> psNext = pHead ;
                pHead = pTemp;
                return 1;
            }
        }
    }
}


extern uint8_t addTail (Node *pElement)
{
    Node *pMove = 0;
    Node *pTemp = 0;

    if(pElement ==0)
    {
        return 0;
    }
    else
    {
        if (pHead == 0)
        {
            if (Create_list(pElement) == 1)
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
             pTemp = (Node* )malloc(sizeof(Node));
             if(pTemp == 0)
             {
                 return 0;
             }
             else
             {
                 memcpy(pTemp,pElement,sizeof(Node));
                 pMove = pHead ;

                 while (pMove -> psNext != 0)
                 {
                     pMove = pMove -> psNext ; // On tail
                 }

                 pMove -> psNext = pTemp;
                 pMove -> psNext -> psNext = 0;
                 return 1;
             }
        }
    }
    return  0;
}




extern void printList(Node *pElement)
{
    uint32_t u32Count = 0;
    Node *pMove = 0;

    if (pHead == 0)
    {
        printf("Empty Linked List");
        return ;
    }
    pMove = pHead ;

    while(pMove != 0)
    {
        printf("Member number %d \nMember content is %d \n",u32Count,pMove->u32Num);
        printf("Member string is %s \n",pMove->c8Name);
        pMove = pMove -> psNext;
        u32Count ++;
    }
}
