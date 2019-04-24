//
//  main.c
//  tableaux
//
//  Created by Ahmed Abdellatif on 24/04/2019.
//  Copyright © 2019 Ahmed Abdellatif. All rights reserved.
//

/*
 [Initialisation]
 tableau[3] = {valeur1,valeur2,valeur3};
 tableau[3] =0;  // toutes les cases valent 0
 tableau[3] ={4}; // premiere case a 4, le reste a 0;
 [Acces au tableau]
 tableau[X] : elements d'indice X (X+1eme element du tableau)
 tableau : adresse du tableau
 *tableau : 1ere element du tableau
 *(tableau+X) : element du indice X
 Note : *(tableau+2) meme chose que tableau[2]
 */

#define TAILLE_TAB_R 3
#define TAILLE_TAB_C 3        // 3X3 X 3X1 = 3X1

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    uint32_t tableau1[TAILLE_TAB_R][TAILLE_TAB_C] = {0};  // intialisation
    uint8_t i = 0;
    uint8_t j = 0;
    uint8_t k = 0;
    uint32_t tableau2[TAILLE_TAB_C][1] = {1,10,100};
    uint32_t mul[TAILLE_TAB_R][1] = {0};
    uint32_t sum = 0;
    
    for(i = 0; i < TAILLE_TAB_R; i++)   //acces au tableau
    {
        for(k = 0; k < TAILLE_TAB_C; k++)
        {
            printf("tableau1[%d][%d] = ",i,k);
            scanf("%d",&tableau1[i][k]); // tableau+i+k == adresse de la 1ere element du tableau;
            }
    }
    for(i = 0; i < TAILLE_TAB_R; i++)
    {
        for(j = 0; j < 1; j++)
            for (k = 0; k < TAILLE_TAB_C; k++)
            {
                sum+=tableau1[i][k]*tableau2[k][j];
        }
        mul[i][j] = sum;
        sum = 0;
    }
printf("prd : \n");
for (i = 0; i < TAILLE_TAB_C; i++) {
    for (j = 0; j < 1; j++)
        printf("%d\t", mul[i][j]);
        printf("\n");
        }
    return 0;
}
