#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "searching.h"

int main()
{
    uint32_t u32Arr[Number_of_elements] = {5,6,10,2,16,17,4,3,10,50};

    printf("The array before sorting was :   \n");
    Print_array(u32Arr);

    Search_num_in_array(u32Arr , 10 );


    Sort_arr_ascend(u32Arr);

    printf("The array after sorting is :   \n");
    Print_array(u32Arr);

    Search_num_in_array(u32Arr , 10 );

}


