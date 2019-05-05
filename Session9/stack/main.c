#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "Linked_list.h"
#include <windows.h>
#include "stack.h"

int main()
{
    Node *pElement1 = 0;
    Node *pElement2 = 0;
    Node *pElement3 = 0;
    uint8_t u8Length_of_stack = 0;

    pElement1 = (Node *) malloc(sizeof(Node));

    if(pElement1 ==0)
    {
        printf("Error in memory allocation process !! \n");
    }
    else
    {
        pElement1 -> u32Num = 10;
        strncpy(pElement1 -> c8Name , "AE1" , STR_LENGTH);

        Create_stack(pElement1);

        free(pElement1);
        pElement1 = 0;
    }

    pElement2 = (Node *) malloc(sizeof(Node));

    if(pElement2 ==0)
    {
        printf("Error in memory allocation process !! \n");
    }
    else
    {
        pElement2 -> u32Num = 20;
        strncpy(pElement2 -> c8Name , "AE2" , STR_LENGTH);

        Push(pElement2);

        free(pElement2);
        pElement2 = 0;
    }


    pElement3 = (Node *) malloc(sizeof(Node));

    if(pElement3 ==0)
    {
        printf("Error in memory allocation process !! \n");
    }
    else
    {
        pElement3 -> u32Num = 30;
        strncpy(pElement3 -> c8Name , "AE3" , STR_LENGTH);

        Push(pElement3);

        Print_stack();
        Get_stack_size(&u8Length_of_stack);
        printf("Now the length of the stack is %d \n\n\n",u8Length_of_stack);

        free(pElement3);
        pElement3 = 0;
    }

    Pop();

    printf ("After the first pop op. the list will be \n");

    Print_stack();
    Get_stack_size(&u8Length_of_stack);

    printf("Now the length of the stack is %d \n\n\n",u8Length_of_stack);


    Pop();

    printf ("After the second pop op. the list will be \n");

    Print_stack();
    Get_stack_size(&u8Length_of_stack);
    printf("Now the length of the stack is %d \n\n\n",u8Length_of_stack);

}






