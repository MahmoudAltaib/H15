#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "Linked_list.h"
#include <windows.h>

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


extern void printList(void)
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


extern uint8_t addElement_by_index(Node *pElement , uint8_t u8Index)
{
    Node *pTemp = 0;
    Node *pTemp1 = 0;
    Node *pMove = 0;
    Node *pPrevious_element = 0;
    uint8_t u8Tail_index = 0;
    uint8_t u8Move_index = 0;

    if(pElement == 0 )
    {
        return 0;
    }
    else
    {
        if(pHead == 0 || u8Index == 0)
        {
            if (addHead(pElement))
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
            pMove = pHead ;
            u8Tail_index = 0 ;

            while (pMove -> psNext !=  0)
            {
                pMove = pMove -> psNext;
                u8Tail_index ++ ;
            }

            if (u8Index > (u8Tail_index +1))
            {
                if (addTail(pElement) == 1)
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
                if (pTemp == 0)
                {
                    return 0;
                }
                else
                {
                    memcpy(pTemp,pElement,sizeof(Node));
                    pMove = pHead ;
                    pPrevious_element = pHead ;

                    while (u8Move_index != (u8Index -1) )
                    {
                    pPrevious_element = pPrevious_element -> psNext ;
                    u8Move_index ++;
                    }
                    u8Move_index = 0;

                    while (u8Move_index != u8Index)
                    {
                        pMove = pMove -> psNext ;
                        u8Move_index ++;
                    }

                     pTemp1 = (Node *) malloc(sizeof(Node));
                    if (pTemp1 == 0)
                    {
                        return 0;
                    }

                    else
                    {
                        memcpy(pTemp1,pMove,sizeof(Node));
                    }

                    pMove = pTemp;
                    pPrevious_element -> psNext = pMove ;
                    pMove -> psNext = pTemp1;
                    return 1;
                }
            }
        }
    }
    return 0;
}


uint8_t Delete_head ()
{
    Node *pTemp = 0;

    if (pHead == 0)
    {
        return 0 ;
    }
    else
    {
       pTemp = pHead -> psNext ;
       pHead = 0;
       free(pHead);
       pHead = pTemp;
       return 1;
    }
    return 0;
}


uint8_t Delete_tail ()
{
    uint8_t u8Tail_index = 0 ;
    uint8_t u8Previous_index = 0;

    Node *pPrevious_to_tail = 0;
    Node *pMove = 0;

    if (pHead == 0)
    {
        return 0 ;
    }
    else
    {
        pMove = pHead ;

       while (pMove -> psNext != 0)
       {
           pMove = pMove -> psNext ;
           u8Tail_index ++ ;
       }

       if (u8Tail_index == 0)
       {
           Delete_head();
       }
       else
       {
           pPrevious_to_tail = pHead ;
           while (u8Previous_index !=  (u8Tail_index -1))
           {
               pPrevious_to_tail = pPrevious_to_tail -> psNext ;
               u8Previous_index ++;
          }
           free(pMove);
           pMove = 0;

           pPrevious_to_tail -> psNext = 0;
       }

       return 1;
    }
    return 0;

}

void Length_of_linked_list (uint8_t *pLength)
{
    Node *pMove = 0;
    *pLength = 1;
    pMove = pHead ;

    while (pMove -> psNext != 0)
    {
        pMove = pMove -> psNext ;
       (*pLength) ++;
    }
}
