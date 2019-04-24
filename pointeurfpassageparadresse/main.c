//
//  main.c
//  pointeurfpassageparadresse
//
//  Created by Ahmed Abdellatif on 23/04/2019.
//  Copyright © 2019 Ahmed Abdellatif. All rights reserved.
//
/*
 [VARIABLES]
 maVariable : valeur de la variable
 &maVariable : adresse de la variable
 [POINTEUR]
 *monPointeur = NULL ou maPointeur = &maVariable
 (declaration et intialistion d'un pointeur)
 monPointeur   : adresse de la variable pointee
 *monPoitneur   : valeur de la variable pointee
 &monPointeur   : adresse du pointeur
*/

#include <stdio.h>

int change_nombre(int *nb);
int change_nombre(int *nb)
{
    *nb = 100;
    return *nb;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int nombre = 0;
    printf("nombre = %d\n",nombre);
    nombre = change_nombre(&nombre);
    printf("nombre = %d\n",nombre);
    
    return 0;
}
