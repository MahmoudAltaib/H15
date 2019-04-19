#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define RIGHT 1
#define LEFT 2

uint32_t u32Result;

uint32_t Rotate(uint32_t u32Num, uint32_t u32Numb_of_rotations, uint32_t u32Direction, uint32_t u32Numb_of_bits_in_Num);

int main()
{
        uint32_t u32Num = 0;
		uint32_t u32Num_of_rotations = 0;
		uint32_t u32Direction = 0;
		uint32_t u32Num_of_bits_in_Num = 0;


	int operation = 0;
	do
	{
		 u32Num = 0;
		 u32Num_of_rotations = 0;
		 u32Direction = 0;
		 u32Num_of_bits_in_Num = 0;

system("CLS");


	printf("\nEnter the number you want to rotate :    ");
	scanf("%u", &u32Num);
	fflush(stdin);

	printf("\nEnter the number of rotations :    ");
	scanf("%u", &u32Num_of_rotations);

	printf("\nEnter the direction of the rotation (  1) RIGHT        2) LEFT )  :    ");
	scanf("%u", &u32Direction);

	printf("\nEnter the number of bits of the used number (8 bits integer or 16 bits or ...etc :    ");
	scanf("%u", &u32Num_of_bits_in_Num);

	u32Result = Rotate(u32Num, u32Num_of_rotations, u32Direction, u32Num_of_bits_in_Num);


	printf("The number after rotation is %d \n\n\n", u32Result);


	printf("Do you want to make another operation ?  1)Yes     2) No \n");
	scanf("%d", &operation);

	} while(operation != 2);


}


uint32_t Rotate(uint32_t u32Num, uint32_t u32Numb_of_rotations, uint32_t u32Direction, uint32_t u32Numb_of_bits_in_Num)
{
	uint32_t u32Original_number = 0;
	uint32_t u32Remained = 0;
	u32Original_number = u32Num;  /*Copying the original number into another variable */

	if (u32Direction == RIGHT)
	{
		u32Num = u32Num >> u32Numb_of_rotations;
		u32Remained = u32Original_number << (u32Numb_of_bits_in_Num - u32Numb_of_rotations);
		u32Num = u32Num | u32Remained;
		u32Result = u32Num;
	}

	else if (u32Direction == LEFT)
	{
		u32Num = u32Num << u32Numb_of_rotations;
		u32Remained = u32Original_number >> (u32Numb_of_bits_in_Num - u32Numb_of_rotations);
		u32Num = u32Num | u32Remained;
		u32Result = u32Num;
	}


	return u32Result;
}
