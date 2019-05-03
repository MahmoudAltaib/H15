#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED
#include "inttypes.h"
#include "string.h"
#define STR_LEN 20

typedef struct StNode
{
    int x;
    char szName [STR_LEN];
    struct StNode * pNext;
}Node;
extern uint8_t CreateList(Node*n);
extern uint8_t AddHead(Node*pElement);
extern uint8_t AddTail(Node*pElement);
extern void printlist (void);

#endif // LINKED_LIST_H_INCLUDED
