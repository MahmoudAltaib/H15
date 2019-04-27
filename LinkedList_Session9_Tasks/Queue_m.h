#ifndef QUEUE_M_H_INCLUDED
#define QUEUE_M_H_INCLUDED
#include "LinkedList.h"

extern uint8_t Create_Queue(Node *n);
extern uint8_t queue_enqueue(Node *pElement);
extern uint8_t queue_dequeue(Node *pElement);
extern void queue_Print(void);
extern uint8_t queue_getSize(int *x);


#endif // QUEUE_M_H_INCLUDED
