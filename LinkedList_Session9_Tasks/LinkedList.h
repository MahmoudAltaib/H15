#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include <inttypes.h>
#define STR_LEN 20

typedef struct stNode
{
    int x;
    char szName[STR_LEN];
    struct stNode *pNext;
}Node;

extern uint8_t CreateList(Node *n); //Create a new Linked List with this node
extern uint8_t addHead(Node *pElement); //Create a new Head for a Linked List with this node
extern uint8_t addTail(Node *pElement); //Create a new Tail for a Linked List with this node
extern void PrintList(void);
extern uint8_t deleteHead();
extern uint8_t deleteTail(Node *pElement);
extern uint8_t addElement(int index,Node *pElement);
extern uint8_t LL_getSize(int *LLsize);
extern uint8_t index_insert(int index, Node *pElement);
#endif // LINKEDLIST_H_INCLUDED
