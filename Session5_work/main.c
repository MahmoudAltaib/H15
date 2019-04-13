#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main()
{
	int32_t i32Num1 = 0;
    int32_t i32Num2 = 0;
	uint32_t operation = 0;

	do {

		system("CLS");

		printf("This program swaps two values \n\n(Note that the algorithm used in this program will allow only a range of 2^16) \n\n");

		printf("Please enter number 1 :     ");
		scanf(" %d", &i32Num1);

		printf("Please enter number 2 :     ");
		scanf(" %d", &i32Num2);

        printf("The numbers before swapping were : Num1 = %d   Num2 = %d    \n",i32Num1,i32Num2);

        i32Num1 = i32Num1<<16|i32Num2;
        i32Num2 = i32Num1>>16;
        i32Num1 = i32Num1<<16;
        i32Num1 = i32Num1>>16;

        int32_t n = i32Num1 | (~(-5));
        printf("%d",n);

        printf("The numbers after swapping are : Num1 = %d   Num2 = %d    \n",i32Num1,i32Num2);

		do {

			printf("\n\nDo you want to continue ?  1) Yes    2)No \n");
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
