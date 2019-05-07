//
//  main.c
//  strcatimpl
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
char strconcatener(signed char mot1[64],signed char mot2[64]);
char strconcatener(signed char mot1[64],signed char mot2[64])
{
    signed char temporaire[128];
    int temp=0;
    int i = 0;
    int j = 0;
    for (i=0; mot1[i]!='\0';i++)
    {
        temporaire[i] = mot1[i];
        temp =i;
    }
    for (j=0; mot2[j]!='\0';j++)
    {
        temporaire[temp+1]=mot2[j];
        temp++;
    }
    return temporaire;
}
int main(int argc, const char * argv[]) {
    signed char mot1[64] = "Ahmed";
    signed char mot2[64] = "Hello";
    signed char res[128] = {0};
    res = strconcatener(mot1, mot2);
    printf("%s",res);
    return 0;
    
}
