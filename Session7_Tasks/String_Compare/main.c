#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

uint32_t u32Get_length(char c8Str[100]);
uint32_t u32Compare (char c8Str1[100],char c8Str2[100]);

int main()
{
    uint32_t u32Operation = 0;
    char c8String1[100] = {0};
    char c8String2[100] = {0};

    uint32_t (*pfu32Compare)(char c8Str1[100],char c8Str2[100]) = 0;

    pfu32Compare = &u32Compare ;
do{

    u32Operation = 0;

    printf("Enter  string1  :   ");
    scanf("%s", c8String1);

    printf("\nEnter  string2  :    ");
    scanf("%s", c8String2);

    if (pfu32Compare(c8String1,c8String2))
    {
        printf("\n\nThe strings are identical\n" );
    }
    else
    {
        printf("\n\nThe strings are not identical\n" );
    }

    printf("\n\nDo you want to continue ? 1) Yes    2) No  \n");
    scanf("%d",&u32Operation);

  }while (u32Operation != 2);

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

uint32_t u32Compare(char c8Str1[100],char c8Str2[100])
{
    uint32_t u32Size_str1 = 0;
    uint32_t u32Size_str2 = 0;
    uint32_t u32Comparator = 0;

    uint32_t (*pfu32Get_length)(char c8Str[100]) = 0;

    pfu32Get_length = &u32Get_length ;

    u32Size_str1 = (*pfu32Get_length)(c8Str1);
    u32Size_str2 = (*pfu32Get_length)(c8Str2);

    if(u32Size_str1 != u32Size_str2)
    {
        return 0;
    }
    else
    {
        for (u32Comparator = 0 ; u32Comparator < u32Size_str1 ; u32Comparator++)
        {
            if (c8Str1[u32Comparator] !=  c8Str2[u32Comparator])
            {
                return 0;
            }
            else
            {
            }
        }
        return 1;
    }
}

