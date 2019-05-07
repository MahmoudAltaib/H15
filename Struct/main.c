//
//  main.c
//  Struct
//
//  Created by Ahmed Abdellatif on 01/05/2019.
//  Copyright © 2019 Ahmed Abdellatif. All rights reserved.
//

#include <stdio.h>

struct Player
{
    signed char username[256];
    int hp;
    int mp;
};
/* Remplacer "struct Player" par " Joueur; */
typedef struct Player Joueur;
int main(int argc, const char * argv[]) {
    // insert code here...
    Joueur p1 = {"Ahmed",100,100};
    printf("Nom du joueur : %s \n", p1.username);
    printf("HP = %d | MP = %d \n",p1.hp,p1.mp);
    return 0;
}
