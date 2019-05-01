#ifndef LINKED2_H_INCLUDED
#define LINKED2_H_INCLUDED
#include<inttypes.h>
typedef struct stnode
{
    char stname[20];
    int x;
    struct stnode *pnext;
}node;
extern uint8_t create_list (node*n);


#endif // LINKED2_H_INCLUDED
