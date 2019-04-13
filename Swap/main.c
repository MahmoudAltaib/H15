//
//  main.c
//  Swap
//
//  Created by Ahmed Abdellatif on 12/04/2019.
//  Copyright © 2019 Ahmed Abdellatif. All rights reserved.
//

#include <stdio.h>
#include <inttypes.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    uint8_t N8_1=0;
    uint8_t N8_2=0;
    uint8_t temp=0;
    
    printf("Hello, This is an Automated Message\n");
    printf("N1 = ");
    scanf("%d",&N8_1);
    printf("N2 = ");
    scanf("%d",&N8_2);
    
    temp = N8_1;
    N8_1 = N8_2;
    N8_2 = temp;
    
    printf("New Numbers : N1 = %d\n",N8_1);
    printf("New Numbers : N2 = %d\n",N8_2);
    
    return 0;
}
