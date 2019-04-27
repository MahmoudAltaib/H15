#ifndef STACK_M_H_INCLUDED
#define STACK_M_H_INCLUDED
#include "LinkedList.h"

extern uint8_t Create_Stack(Node *n);
extern uint8_t stack_push(Node *pElement);
extern uint8_t stack_pop(Node *pElement);
extern void stack_Print(void);
extern uint8_t stack_getSize(int *x);

#endif // STACK_M_H_INCLUDED
