#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "Linked_list.h"
#include <windows.h>
#include "queue.h"

extern uint8_t Create_queue(Node *pElement)
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

extern uint8_t Enqueue(Node *pElement)
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

extern uint8_t Dequeue()
{
    if( Delete_head() == 0 )
    {
        return 0;
    }
    else
    {
        return 1;
    }
    return 0;
}


extern void Get_queue_size(uint8_t *pu8Get_size)
{
    Length_of_linked_list(pu8Get_size);
}


extern void Print_queue(void)
{
    printList();
}



