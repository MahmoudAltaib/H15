//
//  main.c
//  struct2
//
//  Created by Ahmed Abdellatif on 01/05/2019.
//  Copyright © 2019 Ahmed Abdellatif. All rights reserved.
//

#include <stdio.h>
#include <string.h>

typedef struct player
{
    signed char Nom[256];
    int hp;
    int mp;
}joueur;

int main(int argc, const char * argv[]) {
    // insert code here...
    joueur player1 = {"Ahmed",100,100};
    printf("Nom du joueur : %s\n",player1.Nom);
    printf(" HP = %d | MP = %d\n",player1.hp,player1.mp);
    strcpy(player1.Nom,"Abdellatif");       // on peut pas dire player1.Nom = "Abdellatif" parceque c'est une chaines de caracteres;
    player1.hp-=60;
    player1.mp+=1000;
    printf("Nom du joueur : %s\n",player1.Nom);
    printf(" HP = %d | MP = %d\n",player1.hp,player1.mp);
    
    return 0;
}
