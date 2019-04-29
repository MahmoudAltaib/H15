#ifndef linkedlist
#define linkedlist

#include <inttypes.h>

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
extern void printList(void);
extern uint8_t addElement_by_index(Node *pElement , uint8_t u8pIndex);
extern uint8_t Delete_head ();
extern uint8_t Delete_tail ();
extern void Length_of_linked_list (uint8_t *pLength);


#endif




