#include "Queue_m.h"
extern uint8_t Create_Queue(Node *n)
{
    return CreateList(n);
}

extern uint8_t queue_enqueue(Node *pElement)
{
    return addTail(pElement);
}

extern uint8_t queue_dequeue(Node *pElement)
{
    return deleteHead(pElement);
}

extern void queue_Print(void)
{
PrintList();
}

extern uint8_t queue_getSize(int *x)
{
return LL_getSize(x);
}
