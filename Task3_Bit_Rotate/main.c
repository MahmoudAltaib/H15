#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
unsigned int rotate(unsigned int index, unsigned int Num_Rotations, unsigned int Number);
int main()
{
unsigned int Number = 0;
unsigned int index = 0;
unsigned int Num_Rotations = 0;

    printf("Enter Number to Rotate:\n");
    scanf("%u",&Number);

    printf("Enter Index of the Bit:\n");
    scanf("%u",&index);


    printf("Enter Number of Bits from the Index to Rotate:\n");
    scanf("%u",&Num_Rotations);

    printf("Binary representation of the number:%u\n",Number);
    printf("Binary representation after rotation:%u\n",rotate(index,Num_Rotations,Number));

    return 0;
}

unsigned int rotate(unsigned index, unsigned Num_Rotations, unsigned Number)
{
unsigned int N_Bits = 32;
unsigned int Num_Mask = ( Number<<(N_Bits-index) ) >> (N_Bits-index);
return ( ( ( Number>>(index+Num_Rotations) ) | ( ( (Number>>index)<<(N_Bits-Num_Rotations) )>>index ) )<<index ) | Num_Mask;

}
