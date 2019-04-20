#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

uint32_t u32Get_length(char c8Str[100]);





int main()
{
    uint32_t u32Size = 0;
    char c8String[100] = {0};

    uint32_t (*pfu32Get_length)(char c8Str[100]) = 0;

    pfu32Get_length = &u32Get_length ;

    printf("Enter the string you want (make sure that you end your text with null operator or the result will not be accurate) :    ");
    scanf("%s", c8String);

    u32Size = (*pfu32Get_length)(c8String);

    printf("The size of the entered string is %d",u32Size);
    return 0;
}

uint32_t u32Get_length(char c8Str[100])
{



    uint32_t u32Checker = 0;
    uint32_t u32Num_of_bytes = 0;

    for (u32Checker =0;u32Checker<100;u32Checker ++)
    {
        if (c8Str[u32Checker] != '0') /*   The 0 means Null in ASCII code */
        {
            u32Num_of_bytes ++;
        }
        else
        {
            return u32Num_of_bytes ;
        }
    }
    return u32Num_of_bytes;
}

