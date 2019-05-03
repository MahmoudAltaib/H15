#include "Linked_List.h"
#include <stdio.h>
#include "string.h"
#include <stdlib.h>
#define STR_LEN 20
static Node * pHead =0;
extern uint8_t CreateList(Node*n)
{
    if (pHead != 0)
    {
        return 0; //failure
    }
    else
    {
        pHead=(Node*)malloc(sizeof(Node));
        if (pHead==0)
        {
            return 0;
        }
        else
        {
            memcpy (pHead,n,sizeof(Node));
            pHead -> pNext=0;
            return 1;

        }
    }
}
extern uint8_t AddHead(Node*pElement)
{
    Node * pTmp = 0;
    if (pElement == 0)
    {
        return 0;
    }
    if (pHead == 0)
    {
        if (CreateList (pElement) == 1)
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
        pTmp = (Node*) malloc (sizeof(Node));
        if (pTmp ==0 )
        {
            return 0;
        }
        else
        {
            memcpy(pTmp, pElement, sizeof (Node));
            pTmp -> pNext = pHead ;
            pHead = pTmp;
            return 1;
        }
    }
    return 0;
}
extern uint8_t AddTail(Node*pElement)
{
    Node*pTmp=0;
    Node * pMove=0;
    if (pElement ==0)
        return 0;
    if (pHead == 0)
    {
        if(CreateList(pElement) == 1)
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
        pTmp = (Node*)malloc(sizeof(Node));
        if (pTmp ==0)
        {
            return 0;
        }
        else
        {
            memcpy (pTmp , pElement, sizeof (Node));
            pMove = pHead;
            while (pMove -> pNext != 0)
            {
                pMove = pMove -> pNext;//on tail
            }
            pMove -> pNext = pTmp;
            pMove -> pNext -> pNext =0;
            }
    }
    return 1;
}
extern void printlist (void)
{
    Node* pMove=0;
    uint8_t u8cnt=0;
    if (pHead == 0)
    {
        printf("Linked List is Empty\n");
        return ;
    }
    pMove = pHead ;
    while (pMove  != 0)
    {
        printf ("Member No: %d \n Member Value = %d \n Member String= %s\n" , u8cnt, pMove -> x, pMove ->szName);
        pMove =pMove ->pNext ;
        u8cnt++;

    }
}























