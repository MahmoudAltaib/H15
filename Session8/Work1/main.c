/*
 * main.c
 *
 *  Created on: Apr 26, 2019
 *      Author: A.Elkady
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main()
{
	int arr[2][3] = {0};
	int (*pArr)[3] = arr;
	int i = 0, j = 0, k = 0;

	for(i=0;i<2;i++)
	{
		for(j = 0;j<3;j++)
		{
			*((*(pArr+i)+j)) = k;
			k++;
		}
	}

	for(i=0;i<2;i++)
		{
			for(j = 0;j<3;j++)
			{
				printf("%d   %d   \n",arr[i][j],*((*(pArr+i)+j)));
			}
		}


}
