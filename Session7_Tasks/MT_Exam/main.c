#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "functions.h"


int main()
{
    uint32_t u32Repeat_operation = 0;
    uint32_t u32Arr[Num_of_elements] = {0};
    uint32_t u32Num_of_max_occurence = 0;

    do {
        Get_matrix(&u32Arr[0]);

        u32Num_of_max_occurence = u32Max_occurence(u32Arr);

        printf("The number of the maximum occurence equals   %d",u32Num_of_max_occurence);

		printf("\n\nDo you want to make another operation     ?   1) Yes      2) No     \n");
		scanf(" %d", &u32Repeat_operation);

	   } while (u32Repeat_operation != 2);

    return 0;
}
