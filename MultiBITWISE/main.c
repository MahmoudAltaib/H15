//
//  main.c
//  MultiBITWISE
//
//  Created by Ahmed Abdellatif on 13/04/2019.
//  Copyright © 2019 Ahmed Abdellatif. All rights reserved.
//

#include <stdio.h>
#include <inttypes.h>

uint8_t u8Remainder (uint8_t N)          //remainder for even and odd detection
{
    uint8_t u8rem=0;
    u8rem=N&00000001; //Masking
    return(u8rem);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    uint8_t u8Num=0;
    uint32_t u32ShNum=0;
    uint32_t u32ans=0;
    uint8_t u8weight=0;
    
    printf("N = ");
    scanf("%d",&u8Num);
    printf("Weight = ");
    scanf("%d",&u8weight);
        if(u8Remainder(u8weight)==1) // odd number case after calling func.
        {
            u32ShNum=(u8Num<<(u8weight/2));
                u32ans = u32ShNum+u8Num;
            printf("Answer N x 2 = %d\n",u32ans);
                
        }
        else if(u8Remainder(u8weight)==0)
        {
            u32ShNum=(u8Num<<(u8weight/2));
            u32ans = u32ShNum;
            printf("Answer N x 2 = %d\n",u32ans);
        }
    return 0;
}
