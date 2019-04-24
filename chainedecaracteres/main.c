//
//  main.c
//  chainedecaracteres
//
//  Created by Ahmed Abdellatif on 24/04/2019.
//  Copyright © 2019 Ahmed Abdellatif. All rights reserved.
//
/*
 [Fonction des chaines]
 strcpy() : copie une chaine dans une autre (destination,source)
 strlen() : longeur de chaine (sans caractere de la fin de chaine)
 strcmp() : comparer deux chaines (lexicographiquement)
 strcat() : concatener deux chaines (fusionner)
 strstr() : chercher une chaine dans une autre
 strchr() : chercher 1ere occurance du caractere
 */
#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    signed char mot1[10] = "Bienvenue";
    signed char mot2[10] = "Hello";
    int test = strcmp(mot1,mot2);
    if (test == 1)
    {
        printf("les deux mots sont les meme\n");
    }
    else if (test < 0)
    {
        printf("%s < %s\n",mot1,mot2);
    }
    else
    {
        printf("%s > %s\n",mot1,mot2);
    }
    return 0;
    
   /* sprintf(mot2,"Ahmed",5);
    printf("%s",mot2);
   */
}
