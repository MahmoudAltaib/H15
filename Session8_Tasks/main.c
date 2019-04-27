/*
 * main.c
 *
 *  Created on: Apr 27, 2019
 *      Author: A.Elkady
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct stnode
{
	uint32_t u32Num ;
	struct stnode *psNode ;
}Node;

int main()
{
	Node *peHead = 0;
	Node *pe1    = 0;
	Node *pe2    = 0;

	peHead = (Node *) malloc(sizeof(Node));
	peHead->u32Num = 75 ;
	peHead->psNode   = pe1 ;

	pe1    = (Node *) malloc(sizeof(Node));
	pe1->u32Num = 65 ;
	pe1->psNode = pe2 ;

	pe2    = (Node *) malloc(sizeof(Node));
	pe2->u32Num =  85 ;
	pe2->psNode = 0 ;
	
	


}
