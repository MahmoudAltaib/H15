#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define RIGHT 1
#define LEFT 2

uint8_t u8Result;

uint8_t Rotate(uint8_t u8Num, uint8_t u8Numb_of_rotations, uint8_t u8Direction, uint8_t u8Numb_of_bits_in_Num);

int main()
{
	
	
	int operation = 0;
	do
	{
		uint8_t u8Num = 0;
		uint8_t u8Num_of_rotations = 0;
		uint8_t u8Direction = 0;
		uint8_t u8Num_of_bits_in_Num = 0;
		

		system("CLS");

	printf("\nEnter the number you want to rotate :    ");
	scanf_s("%d", &u8Num);

	printf("\nEnter the number of rotations :    ");
	scanf_s("%d", &u8Num_of_rotations);

	printf("\nEnter the direction of the rotation (  1) RIGHT        2) LEFT )  :    ");
	scanf_s("%d", &u8Direction);

	printf("\nEnter the number of bits of the used number (8 bits integer or 16 bits or ...etc :    ");
	scanf_s("%d", &u8Num_of_bits_in_Num);

	u8Result = Rotate(u8Num, u8Num_of_rotations, u8Direction, u8Num_of_bits_in_Num);

	
	printf("The number after rotation is %d \n\n\n", u8Result);


	printf("Do you want to make another operation ?  1)Yes     2) No \n");
	scanf_s("%d", &operation);

	} while(operation != 2);
	

}


uint8_t Rotate(uint8_t u8Num, uint8_t u8Numb_of_rotations, uint8_t u8Direction, uint8_t u8Numb_of_bits_in_Num)
{
	uint8_t u8Original_number = 0;
	uint8_t u8Remained = 0;
	u8Original_number = u8Num;  /*Copying the original number into another variable */

	if (u8Direction == RIGHT)
	{
		u8Num = u8Num >> u8Numb_of_rotations;
		u8Remained = u8Original_number << (u8Numb_of_bits_in_Num - u8Numb_of_rotations);
		u8Num = u8Num | u8Remained;
		u8Result = u8Num;
	}

	else if (u8Direction == LEFT)
	{
		u8Num = u8Num << u8Numb_of_rotations;
		u8Remained = u8Original_number >> (u8Numb_of_bits_in_Num - u8Numb_of_rotations);
		u8Num = u8Num | u8Remained;
		u8Result = u8Num;
	}


	return u8Result;
}
