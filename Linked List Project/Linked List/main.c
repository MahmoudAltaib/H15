#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "string.h"
#include "Searching.h"
int main()
{
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
       // deleteHead();
        //deleteTail();

        free(pElement);
        pElement = 0;
        printList();
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

        //----------------------------------------------------------------------- ADD ELEMENT BY INDEX
        pElement = (Node *) malloc(sizeof(Node));
        if(pElement == 0)
        {
            printf("ERROR");
        }
        else
        {
            pElement -> x = 250;
            strncpy(pElement -> stName , "HAKUNA MATATA", STR_LEN);

            if(addElementByIndex(pElement,1) == 1)
            {
                printList();
                printf("\n");
            }
            free(pElement);
            pElement = 0;

        }








        //----------------------------------------------------------------------------------------------------------------
        // LINEAR SEARCH
        /*uint8_t arr[6] = {1,5,10,15,7,3};
        int result = 0;
         if(linearSearch(arr,7,&result) == 1)
         {
                printf("%d",result);

         }*/

    return 0;
}
