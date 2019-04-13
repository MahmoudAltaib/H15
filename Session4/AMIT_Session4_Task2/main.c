#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>


int main()
{
	int32_t i32Num1 = 0;
    int32_t i32Num2 = 0;
	uint32_t operation = 0;
	uint32_t i32Method = 0;


	do {
		system("CLS");

		printf("This program swaps two values \n Not that method2 will allow the only a range of 2^16 \n");

		printf("Please enter number 1 :     ");
		scanf(" %d", &i32Num1);

		printf("Please enter number 2 :     ");
		scanf(" %d", &i32Num2);

		printf("Please choose an algorithm  1) Method1     2)Method2 \n");
		scanf(" %d", &i32Method);

		if (i32Method == 1)    /*The first method using remainder operator */
		{
		    printf("The numbers before swapping were : Num1 = %d   Num2 = %d    \n",i32Num1,i32Num2);

			int32_t i32Swap = i32Num1;
			i32Num1 = i32Num2;
			i32Num2 = i32Swap;

			printf("The numbers after swapping are : Num1 = %d   Num2 = %d    \n",i32Num1,i32Num2);
		}


		else if (i32Method == 2)
		{
            printf("The numbers before swapping were : Num1 = %d   Num2 = %d    \n",i32Num1,i32Num2);

		    i32Num1 = i32Num1<<16|i32Num2;
		    i32Num2 = i32Num1>>16;
		    i32Num1 = i32Num1<<16;
		    i32Num1 = i32Num1>>16;

		    printf("The numbers after swapping are : Num1 = %d   Num2 = %d    \n",i32Num1,i32Num2);
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
