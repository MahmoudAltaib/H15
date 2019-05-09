#ifndef LISTPROJECT_H_INCLUDED
#define LISTPROJECT_H_INCLUDED
#include "inttypes.h"
#define STR_LEN 20
typedef struct stNode
{
    int degree;
    int ID;
    char stName[STR_LEN];
    struct stNode *pNext;
}Node;

extern uint8_t createList(Node *n);
extern uint8_t addHead(Node *pElement);
extern uint8_t addTail(Node *pElement);
extern void printmembers(void);



#endif
