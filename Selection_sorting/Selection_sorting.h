#ifndef Selection_sorting
#define Selection_sorting

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define Number_of_elements 15

#if Number_of_elements <= 16
#define Number_of_itterations 16/4

#elif (Number_of_elements >16 && Number_of_elements <= 32)
#define Number_of_itterations 32/4

#endif

extern void Swap(uint32_t *pu32Element1 ,uint32_t *pu32Element2);
extern void Selection_sort_array(uint32_t *pu32Arr);
extern void Bubble_sort_array(uint32_t *pu32Arr);
extern void Merge_sort_array(uint32_t *pu32Arr1 , uint32_t *pu32Arr2);


#endif // Selection_sorting
