//
//  main.c
//  malloc
//
//  Created by Ahmed Abdellatif on 01/05/2019.
//  Copyright © 2019 Ahmed Abdellatif. All rights reserved.
/*
 sizeof(<donnee>)        : retourne la taille en octets d'une donnee
 malloc(<taille_en_octets>) : allouer dynamiquement une zone memoire
 free(<donnee_allouee>) liberer la memoire alloue dynamiquement x free / x malloc  in windows
 calloc(<donnee>,<taille_en_octets>) : alloue et initialise tout a 0
 realloc(<donnee>,<nouvelle_taille>) : realloue un espace memoire;
 */

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int nombreJoueur = 0;
    int *listeJoueurs = NULL;
    int i;
    printf("Combien de Joueur ?");
    scanf("%d",&nombreJoueur);
    listeJoueurs = malloc(sizeof(int)*nombreJoueur);
    if (listeJoueurs == NULL)
    {
        exit(1);
    }
    for( i =0 ; i < nombreJoueur ; i++)
    {
        printf("Joueur %d -> numero %d\n", i + 1, i * 3);
        listeJoueurs[i] = i * 3;
    }
    for (i = 0; i < nombreJoueur ; i++)
    {
        printf("[%d]",*(listeJoueurs+i));
    }
    printf("Adresse de la liste : %p",listeJoueurs);
    
    printf("\n ----------------- \n");
    
    nombreJoueur = 5;
    listeJoueurs = realloc(listeJoueurs,nombreJoueur*sizeof(int));
    if (listeJoueurs == NULL)
    {
        exit(1);
    }
    for( i =0 ; i < nombreJoueur ; i++)
    {
        printf("Joueur %d -> numero %d\n", i + 1, i * 3);
        listeJoueurs[i] = i * 3;
    }
    for (i = 0; i < nombreJoueur ; i++)
    {
        printf("[%d]",*(listeJoueurs+i));
    }
    printf("Adresse de la liste : %p \n",listeJoueurs);
    return 0;
}
