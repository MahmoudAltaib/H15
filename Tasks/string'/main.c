#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *pstr = "hello World";
    *(pstr+6)='M';
    return 0;
}
