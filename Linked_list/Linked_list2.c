#include <linked2.h>
node*phead=0;
extern uint8_t create_list (node*n)
{
if(phead!=0)
{
   return 0;
}
}
else
{
    phead=(node*)malloc(sizeof (node));
    { if{
        phead=0
        return 0;
        }
        else

        { memcpy (phead, n ,sizeof(node))
        phead->pnext=0;
        return 1;
        }
    }
}

}
