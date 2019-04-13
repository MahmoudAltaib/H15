//
//  main.c
//  ODDEVENBITWISE
//
//  Created by Ahmed Abdellatif on 13/04/2019.
//  Copyright © 2019 Ahmed Abdellatif. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    uint8_t u8bit=0;
    uint8_t u8rem=0;
    
    printf("Hello ! Please Enter a Number = ");
    scanf("%d",&u8bit);
    
    u8rem=u8bit&00000001; //Masking
    if(u8rem==1)
    {
       printf("%d is ODD\n",u8bit);
    }
    else if(u8rem==0)
    {
        printf("Remainder is %d, Number %d is EVEN\n",u8rem,u8bit);
    }
    
    return 0;
}
