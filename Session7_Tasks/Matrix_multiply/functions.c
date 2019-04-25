#include <stdio.h>

#include<inttypes.h>

#include "functions.h"

void Get_matrix(uint32_t *pu32Mat)
{
	uint32_t u32Repeat_row = 0;
	uint32_t u32Repeat_column = 0;

	for (u32Repeat_row = 0; u32Repeat_row < Num_of_rows; u32Repeat_row++)
	{
		for (u32Repeat_column = 0; u32Repeat_column < Num_of_columns; u32Repeat_column++)
		{
			printf("Enter the element number %d   in Row   %d     :     ", u32Repeat_column, u32Repeat_row);
			scanf(" %d", pu32Mat);
			*pu32Mat ++;
		}
	}
}


void Print_matrix(uint32_t *pu32Mat)
{
	uint32_t u32Repeat_row = 0;
	uint32_t u32Repeat_column = 0;

	printf("Matrix =  \n ");

		for (u32Repeat_row = 0; u32Repeat_row < Num_of_rows; u32Repeat_row++)
		{
			for (u32Repeat_column = 0; u32Repeat_column < Num_of_columns; u32Repeat_column++)
			{
				printf("          %d\t", *pu32Mat);
				*pu32Mat ++;
			}
			printf("  \n");
		}
}


void Mul_matrix(uint32_t u32Arr1[Num_of_rows][Num_of_columns] , uint32_t u32Arr2[Num_of_rows][Num_of_columns] ,uint32_t *pu32Mat)
{
    	uint32_t u32Mul_aid = 0;

        for (u32Mul_aid = 0; u32Mul_aid < 3; u32Mul_aid++)
		{
			*pu32Mat = u32Arr1[0][0] * u32Arr2[0][u32Mul_aid] + u32Arr1[0][1] * u32Arr2[1][u32Mul_aid] + u32Arr1[0][2] * u32Arr2[2][u32Mul_aid];
			*pu32Mat ++;
		}

		for (u32Mul_aid = 0; u32Mul_aid < 3; u32Mul_aid++)
		{
			*pu32Mat = u32Arr1[1][0] * u32Arr2[0][u32Mul_aid] + u32Arr1[1][1] * u32Arr2[1][u32Mul_aid] + u32Arr1[1][2] * u32Arr2[2][u32Mul_aid];
			*pu32Mat++ ;
		}

		for (u32Mul_aid = 0; u32Mul_aid < 3; u32Mul_aid++)
		{
			*pu32Mat = u32Arr1[2][0] * u32Arr2[0][u32Mul_aid] + u32Arr1[2][1] * u32Arr2[1][u32Mul_aid] + u32Arr1[2][2] * u32Arr2[2][u32Mul_aid];
			*pu32Mat ++;
		}
}

