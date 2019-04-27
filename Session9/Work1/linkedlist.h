#ifndef linkedlist
#define linkedlist

#include <inttypes.h>


#endif

#define STR_LENGTH 10

typedef struct stNode
{
    char c8Name[STR_LENGTH] ;
    uint32_t u32Num ;
    struct stNode *psNext ;

}Node;

extern uint8_t Create_list(Node *Head);
extern uint8_t addHead (Node *pElement);
extern uint8_t addTail (Node *pElement);
extern void printList(Node *pElement);
