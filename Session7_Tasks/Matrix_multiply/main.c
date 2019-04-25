#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include"functions.h"

int main()
{
	uint32_t u32Arr1[Num_of_rows][Num_of_columns] = { 0 };
	uint32_t u32Arr2[Num_of_rows][Num_of_columns] = { 0 };
	uint32_t u32Arr[Num_of_rows][Num_of_columns] = { 0 };

	uint32_t u32Repeat_operation = 0;

	do {

		Get_matrix(&u32Arr1[0][0]);
        Print_matrix(&u32Arr1[0][0]);

		Get_matrix(&u32Arr2[0][0]);
		Print_matrix(&u32Arr1[0][0]);

		printf("The result of M1* M2 =   \n ");

        Mul_matrix(u32Arr1,u32Arr2,&u32Arr[0][0]);
		Print_matrix(&u32Arr[0][0]);

		printf("\n\nDo you want to enter another matrix    ?   1) Yes      2) No     \n");
		scanf(" %d", &u32Repeat_operation);

	} while (u32Repeat_operation != 2);

	return 0;
}


