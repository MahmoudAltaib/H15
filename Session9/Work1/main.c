#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "linkedlist.h"

int main()
{
    Node *pElement1 = 0;
    Node *pElement2 = 0;
    Node *pElement3 = 0;

    pElement1 = (Node *) malloc(sizeof(Node));

    if(pElement1 ==0)
    {
        printf("Error in memory allocation process !! \n");
    }
    else
    {
        pElement1 -> u32Num = 50;
        strncpy(pElement1 -> c8Name , "AElkady" , STR_LENGTH);

        if (Create_list(pElement1) ==1 )
        {

        }
        else
        {

        }
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

            if (addHead(pElement2) ==1 )
            {

            }
            else
            {

            }
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

            if (addTail(pElement3) ==1 )
            {
                printList(pElement3);
            }
            else
            {

            }
            free(pElement3);
        pElement3 = 0;
        }


    }






