#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>


int main()
{
	int32_t i32Num = 0;
	uint32_t operation = 0;
	uint32_t i32Method = 0;


	do {
		system("CLS");

		printf("This program allow the user to enter a number and evaluate it to him whether it's even or odd \n");
		printf("Please enter a number :     ");
		scanf(" %d", &i32Num);

		printf("Please choose an algorithm  1) remainder operator     2)Bit wise \n");
		scanf(" %d", &i32Method);

		if (i32Method == 1)    /*The first method using remainder operator */
		{
			if (i32Num % 2 == 0)
			{
				printf("%d\n", i32Num % 2);
				printf("\n\nThe number is even \n");
			}
			else
			{
				printf("%d\n", i32Num % 2);
				printf("\n\nThe number is odd \n");
			}


		}


		else if (i32Method == 2)
		{
			if ((i32Num & 1) == 1)
			{
				printf("%d\n", i32Num & 1);
				printf("\n\nThe number is odd \n");
			}

			else
			{
				printf("%d\n", i32Num & 1);
				printf("\n\nThe number is even \n");
			}

		}




		else
		{
			printf("\n\nWrong choice please choose a right operation \n");
		}





		do {
			printf("\n\nDo you want to enter another name ?  1) Yes    2)No \n");
			scanf(" %d", &operation);

			if (operation == 1)
			{
				break;
			}

			else if (operation == 2)
			{
				return 0;
			}
			else
			{
				printf("\n\nWrong choice please choose a right option \n");
			}
		} while (operation != 1 || operation != 2);


	} while (operation != 2);
}
