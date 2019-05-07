//
//  main.c
//  struct3
//
//  Created by Ahmed Abdellatif on 01/05/2019.
//  Copyright © 2019 Ahmed Abdellatif. All rights reserved.
//

#include <stdio.h>
#include <string.h>
/*
 (*monPointeur).un_champ=X;
 monpointeur->un_champ = X;   c'est la meme chose;
 on n'utilise la fleche que pour le pointeur
 */
typedef struct player
{
    signed char Nom[256];
    int hp;
    int mp;
}joueur;

void createplayer(joueur *p1);   //fonction prototype "passer par adresse" | joueur est un type de donnees
void createplayer(joueur *p1)
{
    
    strcpy(p1->Nom,"Abdellatif");       // on peut pas dire player1.Nom = "Abdellatif" parce que c'est une chaines de caracteres;
    p1->hp-=60;
    p1->mp+=1000;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    joueur player1 = {"",1000,1000};
    joueur tableau_joueurs[5];
    tableau_joueurs[0].hp = 100;
    tableau_joueurs[1].hp = 200;
    tableau_joueurs[2].hp = 300;
    tableau_joueurs[3].hp = 400;
    tableau_joueurs[4].hp = 500;
    
    createplayer(tableau_joueurs);
    printf("Nom du joueur : %s\n",tableau_joueurs[0].Nom);
    printf(" HP = %d | MP = %d\n",tableau_joueurs[0].hp,tableau_joueurs[0].mp);
    printf("Nom du joueur : %s\n",strcpy(player1.Nom,"AhmedAbdellatif"));
    printf(" HP = %d | MP = %d\n",player1.hp,player1.mp);
    
    return 0;
}
