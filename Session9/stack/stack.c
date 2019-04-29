#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "Linked_list.h"
#include <windows.h>
#include "stack.h"

extern uint8_t Create_stack(Node *pElement)
{
    if (Create_list(pElement) == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
    return 0;
}

extern uint8_t Push(Node *pElement)
{
    if (addTail(pElement) == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
    return 0;
}

extern uint8_t Pop()
{
    if( Delete_tail() == 0 )
    {
        return 0;
    }
    else
    {
        return 1;
    }
    return 0;
}


extern void Get_stack_size(uint8_t *pu8Get_size)
{
    Length_of_linked_list(pu8Get_size);
}


extern void Print_stack(void)
{
    printList();
}


