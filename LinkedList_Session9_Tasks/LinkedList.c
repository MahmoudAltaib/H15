#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>

static Node *pHead = 0;
extern uint8_t CreateList(Node *n)
{
if (pHead != 0)
{
  return 0; //Fail
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
return 0;
}


extern uint8_t addHead(Node *pElement)
{
    Node *pTmp = 0;
    if (pElement == 0)
    {
        return 0;
    }

    if (pHead == 0)
    {
       if(CreateList(pElement))
        return 1;
       else
        return 0;
    }
    else
    {
    pTmp = (Node*) malloc(sizeof(Node));
    if (pTmp == 0)
    {
     return 0;
    }
    else
    {
    memcpy(pTmp, pElement, sizeof(Node));
    pTmp -> pNext = pHead;
    pHead = pTmp;
    return 1;
    }
    }
    return 0;

}

extern uint8_t addTail(Node *pElement)

{
     Node *pTmp = 0;
     Node *pMove = 0;
    if (pElement == 0)
    {
        return 0;
    }

    if(pHead == 0)
    {
     if(CreateList(pElement))
        return 1;
     else
        return 0;
    }
    else
    {
    pTmp = (Node*) malloc(sizeof(Node));
    if(pTmp == 0)
    {
      return 0;
    }
    else
    {
    memcpy(pTmp, pElement, sizeof(Node));
    pMove = pHead;
    while(pMove -> pNext != 0)
    {
        pMove = pMove -> pNext; // after the loop pMove is on the tail
    }
    pMove -> pNext = pTmp;
    pMove -> pNext -> pNext = 0;
    return 1;
    }
    }
    return 0;
}

extern void PrintList(void)
{
uint8_t u8Count = 0;
Node *pMove = 0;
  if(pHead == 0)
  {
      printf("Empty Linked List");
      return;
  }
  pMove = pHead;

  while(pMove != 0)
  {
    printf("Member No: %d\n Member Value = %d\n Member Name = %s\n", u8Count, pMove -> x, pMove -> szName);
    pMove = pMove -> pNext;
    u8Count++;

  }
}


extern uint8_t deleteHead()
{
    if(pHead == 0 && pHead->pNext == 0)
    {
     return 0;
    }
    else
    {

    pHead = pHead->pNext;
    return 1;

    }
    return 0;
}


extern uint8_t deleteTail(Node *pElement)
{   Node *pMove = 0;
    Node *pMove2 = 0;
    if(pHead == 0 && pHead -> pNext == 0)
    {
     return 0;
    }
    else
    {
    pMove = pHead;
    pMove2 = pHead;
   while(pMove -> pNext != 0)
    {
        pMove = pMove -> pNext; // after the loop pMove is on the tail
    }
     *pElement = *pMove;
    while(pMove2 -> pNext != pMove) //To get the element before the tail
    {
        pMove2 = pMove2 -> pNext;
    }
    pMove2 -> pNext = 0;
    return 1;

    }
    return 0;

}

extern uint8_t LL_getSize(int *LLsize)

{
uint8_t u8Count = 0;
Node *pMove = 0;
  if(pHead == 0)
  {
      return 0;
  }
  else
  {
     pMove = pHead;

  while(pMove != 0)
  {
    pMove = pMove -> pNext;
    u8Count++;

  }
  *LLsize = u8Count-1;
  return 1;
  }

return 0;

}


extern uint8_t index_insert(int index, Node *pElement)
{
    Node *pTmp = 0;
    Node *pMove = 0;
    Node *pMove2 = 0;
    if (pElement == 0)
    {
        return 0;
    }

    if (pHead == 0)
    {
       if(CreateList(pElement))
        return 1;
       else
        return 0;
    }
    else
{
    int this_size = 0;
    LL_getSize(&this_size);
    if (index > (this_size + 1) )
        {
            return 0;
        }
    if (index - this_size == 1)
    {
       return addTail(pElement);
    }
    if (index == 0)
    {
       return addHead(pElement);
    }
else
 {


    pTmp = (Node*) malloc(sizeof(Node));
     if (pTmp == 0)
    {
     return 0;
    }
    else
    {

    memcpy(pTmp, pElement, sizeof(Node));
    pMove = pHead;
    pMove2 = pHead;
    for(int i = 0; i < index; i++)
    {
        pMove = pMove->pNext;  //We are in the desired index
    }
    while(pMove2 -> pNext != pMove) //To get the element before the tail
    {
        pMove2 = pMove2 -> pNext;
    }

    pTmp -> pNext = pMove;
    pMove2 -> pNext = pTmp;
    return 1;
    }
 }
}
return 0;
}
