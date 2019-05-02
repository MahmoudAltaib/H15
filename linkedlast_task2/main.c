
#include <stdio.h>
#include <stdlib.h>
#include "mm.h"
#include "string.h"
int main()
{   int choice;
    // CREATE LIST
    Node *pElement = 0;
    pElement = (Node *) malloc(sizeof(Node));

    if(pElement == 0)
    {
        printf("ERROR");
    }
    else
    {
        pElement -> x = 50;
        strncpy(pElement -> stName , "Ahmed", STR_LEN);
        if(createList(pElement) == 1)
        {
            printList();
            printf("\n");
        }
        free(pElement);
        pElement = 0;
    }
        //--------------------------------------------------------------------------------------    ADD HEAD
        pElement = (Node *) malloc(sizeof(Node));
        if(pElement == 0)
        {
            printf("ERROR");
        }
        else
        {
            pElement -> x = 100;
            strncpy(pElement -> stName , "Ezzo", STR_LEN);

            if(addHead(pElement) == 1)
            {
                printList();
                printf("\n");
            }
            free(pElement);
            pElement = 0;

        }
        //-------------------------------------------------------------------------------------     ADD TAIL
        pElement = (Node *) malloc(sizeof(Node));
        if(pElement == 0)
        {
            printf("ERROR");
        }
        else
        {
            pElement -> x = 200;
            strncpy(pElement -> stName , "Putin", STR_LEN);

            if(addTail(pElement) == 1)
            {
                printList();
                printf("\n");
            }
            free(pElement);
            pElement = 0;

        }




 printf("\nPress 1 to delete first node: ");
    scanf("%d", &choice);

    if(choice == 1)
{
extern uint8_t deletehead (Node *pElement);

}



    printf("\nData in the list \n");
    printList();

    return 0;




}
