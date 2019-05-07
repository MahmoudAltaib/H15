//
//  main.c
//  ifndefendif
//
//  Created by Ahmed Abdellatif on 20/04/2019.
//  Copyright © 2019 Ahmed Abdellatif. All rights reserved.
//

#include <stdio.h>
#ifndef TRUE
#define TRUE 1u
#endif
#ifndef FALSE
#define FALSE 0u   //u for unsigned
#endif

#define BMW
#ifdef BMW



#endif



int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
