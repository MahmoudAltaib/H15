#include <stdio.h>
#include <stdlib.h>
#include "inttypes.h"
int fact(int var);

int main()
{
    // FACTORIAL USING RECURSION
    /*unsigned int x = 0;
    printf("please enter the number below\n");
    scanf("%d", &x);
    printf("Result is : %d",fact(x));*/

    //-------------------------------------------------------------------------

    // START OF ARRAYS

    /*int arr[2][3] = {{0,1,2},{3,4,5}};
    printf("%d", arr[0][0]);
    printf("%d", arr[0][1]);
    printf("%d\n", arr[0][2]);
    printf("%d", arr[1][0]);
    printf("%d", arr[1][1]);
    printf("%d", arr[1][2]);*/

    /*int arr[2][3] = {0};
    printf("%p",arr[0][2]);*/
    //----------------------------------------

    // ACCESSING A MULTIDIMENSIONAL ARRAY USING THE NORMAL WAY
    /*int i,j,k;
    int arr[2][3] = {0};
    for(i = 0, k = 0; i < 2; i++)
    {
        for(j = 0; j < 3; j++)
        {
            arr[i][j] = k++;
            printf("%d",arr[i][j]);
        }
    }*/

    //----------------------------------------------------------------------
    //char str[] = {'1','2','3','\0'};
    //char *pStr = "Hello World!";
    //printf("%s",pStr);
    //printf("%s", str);

    //----------------------------------------------------------------------

    // ACCESSING A MULTIDIMENSIONAL ARRAY USING POINTERS

    int arr[2][3] = {0};
    int(*pArr)[3] = arr;
    int i,j,k = 0;
    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 3; j++)
        {
            *((*(pArr + i)) +j) = k; // *** VERY IMPORTANT ***
            k++;
        }
    }
    //---------
    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("%d %d\n",arr[i][j],*((*(pArr + i)) +j)); // THIS PRINTS THE SAME ARRAY TWICE, ONCE USING THE OLD METHOD AND ONE USING POINTERS
        }
    }
    return 0;
}

// END OF MAIN
//--------------------------------------------------------------------------------------------------------------------------------------------------


// FACTORIAL USING RECURSION
/*int fact(int var)
{
    if(var == 1)
    {
        return 1;
    }

    return var * fact(var - 1);
    //--------------------------------------------------------------------------

}*/
