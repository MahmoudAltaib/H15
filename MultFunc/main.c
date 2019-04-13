//
//  main.c
//  MultFunc
//
//  Created by Ahmed Abdellatif on 13/04/2019.
//  Copyright © 2019 Ahmed Abdellatif. All rights reserved.
//
#define N 5
#define T 7
#include <stdio.h>
uint8_t prod(uint8_t Num, uint8_t Count)  //function prototype
{
    uint8_t sum =0;
for(uint8_t ind=Count; ind>0; ind--)
{
    sum+=Num;
}
return (sum);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    uint8_t ans=0;
    ans=prod(N,T);
    printf("Answer = %d\n",ans);
    return 0;
}
