//
//  main.c
//  Devoir1
//
//  Created by Ahmed Abdellatif on 07/04/2019.
//  Copyright © 2019 Ahmed Abdellatif. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int SM = 0;
    printf("Student mark = ");
    scanf("%d",&SM);
    switch (SM)
    {
case 50 ... 60 :
    printf("PASS\n");
    break;
case 61 ... 70 :
    printf("GOOD\n");
    break;
case 75 ... 85 :
    printf("V.GOOD\n");
    break;
case 86 ... 100 :
    printf("EXCELLENT\n");
    break;
        default:
    printf("F\n");
    break;
    }
    return 0;
}
