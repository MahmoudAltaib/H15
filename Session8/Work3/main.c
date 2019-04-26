/*
 * main.c
 *
 *  Created on: Apr 26, 2019
 *      Author: A.Elkady
 */

typedef union
{
	int x;
	char string[8];
}student ;

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main()
{

	student q = {0};

	student *pu = &q;

    q.x = 5;

    pu->string[0] = 6;

    printf("The value of the allocation address is %d",q.x);

}
