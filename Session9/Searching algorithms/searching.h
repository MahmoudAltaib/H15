#ifndef searching
#define searching

#define Number_of_elements 10

extern uint8_t Sort_arr_ascend(uint32_t *pu32Arr );
extern uint8_t Get_lowest_number(uint32_t *pu32Arr , uint32_t *pu32Lowest_num);
extern void Print_array(uint32_t *pu32Arr);
extern void Swap(uint32_t *pu32Element1,uint32_t *pu32Element2);
extern void Search_num_in_array(uint32_t *pu32Arr , uint32_t u32Search_num );
extern void Check_repetition(uint32_t *pu32Arr );


#endif // searching
