//
//  main.c
//  strlen
//
//  Created by Ahmed Abdellatif on 24/04/2019.
//  Copyright © 2019 Ahmed Abdellatif. All rights reserved.
//

#include <stdio.h>
int longeurdechaine(signed char str[128]);
int longeurdechaine(signed char str[128])
{
    int temp=0;
    int i = 0;
    for (i=0; *(str+i)!='\0';i++)          // meme chose que str[i];
    {
        temp =i;
    }
    return temp+1;
}
int main(int argc, const char * argv[]) {
    signed char mot1[128]; //longeur de chaine doit être initialisé
    int taille = 0;
    printf("Please enter your message without spaces \n");
    scanf("%s",mot1);
    taille = longeurdechaine(mot1);
    printf("longeur de votre chaine -> %d\n",taille);
    return 0;
}
