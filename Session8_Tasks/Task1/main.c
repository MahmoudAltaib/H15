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

	char c8Name[10];
	uint32_t u32Grade ;

	struct stnode *psNode ;

}Node;

int main()
{
	Node *peHead = 0;
	Node *pe1    = 0;
	Node *pe2    = 0;

	peHead = (Node *) malloc(sizeof(Node));
	pe1    = (Node *) malloc(sizeof(Node));
	pe2    = (Node *) malloc(sizeof(Node));

	scanf("%s",peHead->c8Name);
	scanf("%u",peHead->u32Grade);
	peHead->psNode = pe1 ;

	scanf("%s",pe1->c8Name);
	scanf("%u",pe1->u32Grade);
	pe1->psNode = pe2 ;

	scanf("%s",pe2->c8Name);
	scanf("%u",pe2->u32Grade);
	pe2->psNode = 0 ;
}
