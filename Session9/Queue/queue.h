#ifndef queue
#define queue

extern uint8_t Create_queue(Node *pElement);
extern uint8_t Enqueue(Node *pElement);
extern uint8_t Dequeue();
extern void Get_queue_size(uint8_t *pu8Get_size);
extern void Print_queue(void);

#endif // queue

