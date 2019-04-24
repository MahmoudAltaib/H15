//
//  main.c
//  pointeur
//
//  Created by Ahmed Abdellatif on 23/04/2019.
//  Copyright © 2019 Ahmed Abdellatif. All rights reserved.
//
int change_nombre(int nb);
int change_nombre(int nb)
{
    nb = 15;
    return nb;
}

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int nombre = 0;
    printf("Nombre = %d\n",nombre);
    nombre = change_nombre(nombre);   //passage par valeur
    printf("Nombre = %d\n",nombre);
    return 0;
}
