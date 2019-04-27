#include "Stack_m.h"

extern uint8_t Create_Stack(Node *n)
{
return CreateList(n);
}
extern uint8_t stack_push(Node *pElement)
{
return addTail(pElement);
}
extern uint8_t stack_pop(Node *pElement)
{
return deleteTail(pElement);
}
extern void stack_Print(void)
{
PrintList();
}
extern uint8_t stack_getSize(int *x)
{
return LL_getSize(x);
}
