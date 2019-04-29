#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "linkedlist.h"
#include <windows.h>
#include "stack.h"

int main()
{
    Node *pElement1 = 0;
    Node *pElement2 = 0;
    Node *pElement3 = 0;
    uint8_t u8Length_of_linked_list = 0;

    pElement1 = (Node *) malloc(sizeof(Node));

    if(pElement1 ==0)
    {
        printf("Error in memory allocation process !! \n");
    }
    else
    {
        pElement1 -> u32Num = 50;
        strncpy(pElement1 -> c8Name , "AElkady" , STR_LENGTH);

        Create_list(pElement1);

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
            pElement2 -> u32Num = 60;
            strncpy(pElement2 -> c8Name , "AElkady1" , STR_LENGTH);

            addHead(pElement2);

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
            pElement3 -> u32Num = 70;
            strncpy(pElement3 -> c8Name , "AElkady2" , STR_LENGTH);
            addElement_by_index(pElement3 , 1);

            printList();
            Length_of_linked_list(&u8Length_of_linked_list);
            printf("Now the length of the linked list is %d \n",u8Length_of_linked_list);

            free(pElement3);
            pElement3 = 0;
        }
    Delete_head ();

    printf ("After head removal the list will be \n");

    printList();
    Length_of_linked_list(&u8Length_of_linked_list);
    printf("Now the length of the linked list is %d \n",u8Length_of_linked_list);


    Delete_tail();

    printf ("After Tail removal the list will be \n");

    printList();
    Length_of_linked_list(&u8Length_of_linked_list);
    printf("Now the length of the linked list is %d \n",u8Length_of_linked_list);



    }






