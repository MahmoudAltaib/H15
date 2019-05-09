#include <stdio.h>
#include <stdlib.h>
#include "ListProject.h"
#include "string.h"
int main()
{

    Node *pElement = 0;
    pElement = (Node *) malloc(sizeof(Node));

    if(pElement == 0)
    {
        printf("list error");
    }
    else
    {
        pElement -> degree = 10;
        pElement -> ID=200;
        strncpy(pElement -> stName , "student_1", STR_LEN);
        if(createList(pElement) == 1)
        {
            printmembers();
            printf("\n");
        }
        free(pElement);
        pElement = 0;
    }

        pElement = (Node *) malloc(sizeof(Node));
        if(pElement == 0)
        {
            printf("list error");
        }
        else
        {
            pElement -> degree = 9;
                    pElement -> ID=201;

            strncpy(pElement -> stName , "student_2", STR_LEN);

            if(addHead(pElement) == 1)
            {
                printmembers();
                printf("\n");
            }
            free(pElement);
            pElement = 0;

        }
             pElement = (Node *) malloc(sizeof(Node));
        if(pElement == 0)
        {
            printf("list error");
        }
        else
        {
            pElement -> degree = 4;
                    pElement -> ID=202;

            strncpy(pElement -> stName , "student_3", STR_LEN);

            if(addHead(pElement) == 1)
            {
                printmembers();
                printf("\n");
            }
            free(pElement);
            pElement = 0;

        }
             pElement = (Node *) malloc(sizeof(Node));
        if(pElement == 0)
        {
            printf("list error");
        }
        else
        {
            pElement -> degree = 8;
                pElement -> ID=203;

            strncpy(pElement -> stName , "student_3", STR_LEN);

            if(addHead(pElement) == 1)
            {
                printmembers();
                printf("\n");
            }
            free(pElement);
            pElement = 0;

        }
             pElement = (Node *) malloc(sizeof(Node));
        if(pElement == 0)
        {
            printf("list error");
        }
        else
        {
            pElement -> degree = 10;
                    pElement -> ID=204;

            strncpy(pElement -> stName , "student_4", STR_LEN);

            if(addHead(pElement) == 1)
            {
                printmembers();
                printf("\n");
            }
            free(pElement);
            pElement = 0;

        }
             pElement = (Node *) malloc(sizeof(Node));
        if(pElement == 0)
        {
            printf("list error");
        }
        else
        {
            pElement -> degree = 2;
                    pElement -> ID=205;

            strncpy(pElement -> stName , "student_5", STR_LEN);

            if(addHead(pElement) == 1)
            {
                printmembers();
                printf("\n");
            }
            free(pElement);
            pElement = 0;

        }
             pElement = (Node *) malloc(sizeof(Node));
        if(pElement == 0)
        {
            printf("list error");
        }
        else
        {
            pElement -> degree = 9;
                    pElement -> ID=206;

            strncpy(pElement -> stName , "student_6", STR_LEN);

            if(addHead(pElement) == 1)
            {
                printmembers();
                printf("\n");
            }
            free(pElement);
            pElement = 0;

        }
             pElement = (Node *) malloc(sizeof(Node));
        if(pElement == 0)
        {
            printf("list error");
        }
        else
        {
            pElement -> degree = 5;
                    pElement -> ID=207;

            strncpy(pElement -> stName , "student_7", STR_LEN);

            if(addHead(pElement) == 1)
            {
                printmembers();
                printf("\n");
            }
            free(pElement);
            pElement = 0;

        }
             pElement = (Node *) malloc(sizeof(Node));
        if(pElement == 0)
        {
            printf("list error");
        }
        else
        {
            pElement -> degree = 1;
            pElement -> ID=208;

            strncpy(pElement -> stName , "student_8", STR_LEN);

            if(addHead(pElement) == 1)
            {
                printmembers();
                printf("\n");
            }
            free(pElement);
            pElement = 0;

        }
             pElement = (Node *) malloc(sizeof(Node));
        if(pElement == 0)
        {
            printf("list error");
        }
        else
        {
            pElement -> degree = 3;
                    pElement -> ID=209;

            strncpy(pElement -> stName , "student_9", STR_LEN);

            if(addHead(pElement) == 1)
            {
                printmembers();
                printf("\n");
            }
            free(pElement);
            pElement = 0;

        }


        pElement = (Node *) malloc(sizeof(Node));
        if(pElement == 0)
        {
            printf("list error");
        }
        else
        {
            pElement -> degree = 6;
                    pElement -> ID=210;

            strncpy(pElement -> stName , "student_10", STR_LEN);

            if(addTail(pElement) == 1)
            {
                printmembers();
                printf("\n");
            }
            free(pElement);
            pElement = 0;

        }



    return 0;
}
