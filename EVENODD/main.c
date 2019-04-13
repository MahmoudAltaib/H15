//
//  main.c
//  EVEN&ODD
//
//  Created by Ahmed Abdellatif on 12/04/2019.
//  Copyright © 2019 Ahmed Abdellatif. All rights reserved.
//

#include <stdio.h>
#include <inttypes.h>

int main(int argc, const char * argv[]) {
    // Variable Decalration
    uint32_t i32Num=0;
    uint8_t i8Rem=0;
    
       printf("Hello This is an Automated Message!\n");
       printf("Please Enter a Number = ");
    scanf("%d",&i32Num);
    i8Rem = i32Num%2;
    if (i8Rem==1)
    {
        printf("%d is an Odd Number\n",i32Num);
    }
    else if (i8Rem==0)
        printf("%d is an Even Number\n",i32Num); //Remainder = (int)i32Num*2; unused approach
    return 0;
}
