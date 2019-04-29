#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "searching.h"

int main()
{
    int32_t i32Num = 0;
    int32_t i32Arr[Num_of_elements] = {1,5,10,15,7,3,2};
    uint32_t u32Result = 0;
    uint8_t u8Return_value =0;

    printf("Enter the number you need to search for   :     \n");
    scanf("%d",&i32Num);

   u8Return_value = linear_search(i32Arr,i32Num,&u32Result);

    if(u8Return_value == 0)
    {
        printf("The number does not exist in the array !! \n");
    }
    else
    {
        printf("Number %d you are searching for is in the index %d of the array \n\n\n ",i32Num,u32Result);
    }
}
