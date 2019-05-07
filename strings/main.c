//
//  main.c
//  strings
//
//  Created by Ahmed Abdellatif on 20/04/2019.
//  Copyright © 2019 Ahmed Abdellatif. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    char str[] = "helloworld!";
    //     = {'H','e',.........} size is defined from what u write
    // ={0}
    char *pstr = "helloworld";
    *(pstr+6)='M';               //bad access because it was created in .rodata for temp variables
    printf("%s",pstr);          
    return 0;
}
