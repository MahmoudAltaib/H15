#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main()
{

	uint32_t i32Num1 = 0;
    uint8_t repeat = 0;
uint8_t operation = 0;

	do {

		system("CLS");

		printf("This program toggles a certain bit \n\n");

		printf("Please enter number 1 :     ");
		scanf(" %d", &i32Num1);
        printf("%d\n",i32Num1);

		for (repeat = 0;repeat <10 ;repeat ++)
        {

            i32Num1 = (i32Num1 & ~(1<<2) ) | ( ~(i32Num1) & (1<<2) )  ;

            printf("%d\n",i32Num1);
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

