#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "linkedlist.h"
#include <windows.h>
#include "stack.h"

static Node *pHead = 0;

uint8_t Create_stack(Node *pElement)
{
    if (Create_list(pElement) == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


