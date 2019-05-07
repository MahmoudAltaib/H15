//
//  main.c
//  pointer
//
//  Created by Ahmed Abdellatif on 19/04/2019.
//  Copyright © 2019 Ahmed Abdellatif. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int i32data = 15;
    int *pi32ref = &i32data;
    
    printf("%d\n",i32data);
    i32data = 20;
    printf("%d\n",*pi32ref);
    printf("%x\n",&i32data);
    printf("%x\n",pi32ref);
    printf("%x\n",&pi32ref);
        i32data++;
        printf("%d\n",i32data);
        (*pi32ref)--;                 //() is crucial
        printf("%d\n",i32data);
    (pi32ref)+=2;                      //increment address by the value of the next add of pointed data type            
    printf("%x\n",pi32ref);
    
    //multidimenssion pointer is decalred ** 

}
