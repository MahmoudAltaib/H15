#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "Linked_list.h"
#include <windows.h>
#include "queue.h"

int main()
{
    Node *pElement1 = 0;
    Node *pElement2 = 0;
    Node *pElement3 = 0;
    uint8_t u8Length_of_queue = 0;

    pElement1 = (Node *) malloc(sizeof(Node));

    if(pElement1 ==0)
    {
        printf("Error in memory allocation process !! \n");
    }
    else
    {
        pElement1 -> u32Num = 10;
        strncpy(pElement1 -> c8Name , "AE1" , STR_LENGTH);

        Create_queue(pElement1);

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

        Enqueue(pElement2);

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

        Enqueue(pElement3);

        Print_queue();
        Get_queue_size(&u8Length_of_queue);
        printf("Now the length of the queue is %d \n\n\n",u8Length_of_queue);

        free(pElement3);
        pElement3 = 0;
    }

    Dequeue();

    printf ("After the first Dequeueing op. the list will be \n");

    Print_queue();
    Get_queue_size(&u8Length_of_queue);

    printf("Now the length of the queue is %d \n\n\n",u8Length_of_queue);


    Dequeue();

    printf ("After the second Dequeueing op. the list will be \n");

    Print_queue();
    Get_queue_size(&u8Length_of_queue);
    printf("Now the length of the queue is %d \n\n\n",u8Length_of_queue);



}






