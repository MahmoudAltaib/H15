//
//  main.c
//  pointertofunction
//
//  Created by Ahmed Abdellatif on 19/04/2019.
//  Copyright © 2019 Ahmed Abdellatif. All rights reserved.
//

#include <stdio.h>



int add(int x,int y) //function definition
{
    int r = x+y;
    return r;
}
int add(int x,int y);  //function prototype


int main(int argc, const char * argv[]) {
    typedef void (*pfun)(void);
    pfun i;    // i is a pointer to function
    // insert code here...
    int res =0;
    int res2 =0;
    int(*pf)(int a, int b)=0;    //declares pointer to function
    pf = add; //
    res = add(3,1);
    printf("%d\n",res);
    res2 = (*pf)(3,1);         // is exactly the same as pf(3,1) while *pf(3,1) is casting
                               // pointer to function excutes only and doesnt
    printf("%d\n",res2);
    
    return 0;
}
