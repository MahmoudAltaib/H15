//
//  main.c
//  BitIndiceSwap
//
//  Created by Ahmed Abdellatif on 18/04/2019.
//  Copyright © 2019 Ahmed Abdellatif. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    uint8_t u8bit=0;
    uint8_t u8radical=0; // radical to store mid 6 bits
    uint8_t u8bin=0;
    printf("Hello, Please Enter a Number in decimal : ");
    scanf("%d",&u8bit);
    u8radical = u8bit&0b01111110; //radical + clearing both front and tail of the byte
    u8bin = u8bit^u8radical;      // xoring to detect the differences between two sets
    printf("%d \n",u8bin);        // just for readability
    if(u8bin==129)
    {
        printf("no need to swap cause both head and tail are 1s \n Res = %d",u8bit);
    }
    else if(u8bin==1)            // tail = 1; head = 0;
    {
        u8bit|=(1<<7);           //setting head to be 1;
        u8bit&=~(128>>7);        //clearing tail to be 0;
        printf("%d",u8bit);
    }
    else if(u8bin==0b10000000)   // tail = 0; head = 1;
    {
        u8bit&=~(1<<7);           //setting head to be 0;
        u8bit|=(128>>7);          //setting tail to be 1;
        printf("%d",u8bit);
    }
    return 0;
}
