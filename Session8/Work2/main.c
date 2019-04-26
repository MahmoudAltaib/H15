/*
 * main.c
 *
 *  Created on: Apr 26, 2019
 *      Author: A.Elkady
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct student
   {
	   int Age ;
	   char Name[10] ;
	   char *p ;
	   char Name21 ;
   }Student;



int main()
{

   Student *ps = 0;

   Student y = {0};

   ps = &y ;

   ps->Age = 25;

   printf("The size of the student structure is %d",sizeof(y));


   return 0;
}
