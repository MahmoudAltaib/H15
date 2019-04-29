#ifndef stack
#define stack

extern uint8_t Create_stack(Node *pElement);
extern uint8_t Push(Node *pElement);
extern uint8_t Pop();
extern void Get_stack_size(uint8_t *pu8Get_size);
extern void Print_stack(void);

#endif // stack

