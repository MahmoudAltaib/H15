//
//  main.c
//  recursive 100functions
//
//  Created by Ahmed Abdellatif on 20/04/2019.
//  Copyright © 2019 Ahmed Abdellatif. All rights reserved.
//

#include <stdio.h>

uint32_t fact(uint32_t var);

int main(int argc, const char * argv[]) {
    // insert code here..
    uint32_t num = 0;
    uint32_t res = 0;
    printf("please enter a number = ");
    scanf("%d",&num);
    res = fact(num);
    printf("%d",res);
    return 0;
}


uint32_t fact (uint32_t var)
{
    if (var==1)
        return 1;
    else
        return var*fact(var-1);
        
}
