#include <stdio.h>
#include <stdlib.h>
typedef struct StNode1
{
    int x;
    struct StNode1*pnext;
}Node1;

typedef struct StNode2
{
    int y;
    struct StNode2*pnext;
}Node2;

int main()
{
    Node1*phead=0;

    phead=(Node1*) malloc (sizeof (Node1));
    Node2*ptail=0;
    phead->pnext=ptail;
    ptail=(Node2*) malloc (sizeof(Node2));
    ptail->pnext=0;
    printf("%d\n",phead);
    printf("%d\n",ptail);
    return 0;
}
