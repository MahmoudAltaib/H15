//
//  main.c
//  liste
//
//  Created by Ahmed Abdellatif on 01/05/2019.
//  Copyright © 2019 Ahmed Abdellatif. All rights reserved.
//

#ifndef __LIST__H__
#define __LIST__H__
// definition du type Booleen
typedef enum
{
    false,
    true,
}Booleen;

// defintion d'une liste
typedef struct ListElement
{
    int valeur;
    struct ListElement *next;
}ListElement, *List;


// prototype
List new_list(void);
Booleen is_empty_list(List li);
int ListLenght(List li);
void print_list(List li);
#endif

