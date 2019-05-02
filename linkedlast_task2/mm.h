#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include "inttypes.h"

#define STR_LEN 20
typedef struct stNode
{
    int x; // data that the node holds
    char stName[STR_LEN];
    struct stNode *pNext;
}Node;

extern uint8_t createList(Node *n);
extern uint8_t addHead(Node *pElement);
extern uint8_t addTail(Node *pElement);
extern uint8_t deletehead(Node *pElement);
extern void printList(void);



#endif // LINKEDLIST_H_INCLUDED
