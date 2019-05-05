#include "Database.h"

static Member *pHead = 0;

extern uint32_t Create_DB( Member *pElement )
{

    if(pHead == 0)
    {
        pHead  = (Member *) malloc(sizeof(Member));

        if(pHead == 0)
        {
            return 0;
        }
        else
        {
            memcpy(pHead , pElement , sizeof(Member));
            pHead -> pNext = 0 ;
            return 1;
        }

    }
    else
    {
        printf("The database is already created ..!! \n");
    }
    return 0;
}

extern void Print_DB(void)
{
    uint32_t u8Count = 0;
    Member *pMove = 0;

    if (pHead == 0 )
    {
        printf("The list is empty \n");
    }
    else
    {
        pMove = pHead ;

        while (pMove != 0)
        {

            printf("** Member  %d    ---------- \n", u8Count);
            printf("   Student's ID   :  %s  \n", pMove -> cStudent_ID);
            printf("   Year of study  :  %d  \n", pMove -> u32Year_of_study);
            printf("   Course1's ID   :  %s  \n", pMove -> ucCourse1_ID);
            printf("   Course1's Grade:  %d  \n", pMove -> u32Course1_grade);
            printf("   Course2's ID   :  %s  \n", pMove -> ucCourse2_ID);
            printf("   Course2's Grade:  %d  \n", pMove -> u32Course2_grade );

            pMove = pMove -> pNext ;

            u8Count ++;
        }

    }
}

extern uint32_t Get_student_info(Member *pElement)
{

    printf("\nEnter Student's ID  :    ");
    scanf("%s",pElement -> cStudent_ID);

    printf("Enter Year of study  :    ");
    scanf("%d",&(pElement -> u32Year_of_study));

    printf("Enter Course1's ID  :    ");
    scanf("%s",pElement -> ucCourse1_ID);

    printf("Enter Course1's Grade  :    ");
    scanf("%d",&(pElement -> u32Course1_grade));

    printf("Enter Course2's ID :    ");
    scanf("%s",pElement -> ucCourse2_ID);

    printf("Enter Course2's Grade  :    ");
    scanf("%d",&(pElement -> u32Course2_grade));

    return 1;
}

extern uint8_t Add_tail_member(Member *pElement)
{
    Member *pMove = 0;
    Member *pTemp = 0;


    if(Is_DB_full() == 0)
    {
        if(pElement == 0)
        {
            return 0;
        }
        else
        {
            if (pHead == 0)
            {
                if (Create_DB(pElement) == 1)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                 pTemp = (Member* )malloc(sizeof(Member));
                 if(pTemp == 0)
                 {
                     return 0;
                 }
                 else
                 {
                     memcpy(pTemp,pElement,sizeof(Member));
                     pMove = pHead ;

                     while (pMove -> pNext != 0)
                     {
                         pMove = pMove -> pNext ;
                     }

                     pMove -> pNext = pTemp;
                     pMove -> pNext -> pNext = 0;
                 }
            }
            return 1;
        }
    }
    else
    {
        printf("\nDatabase is full you can't add members unless you delete any existing member \n!!");
    }
    return  0;
}

extern uint8_t Add_head_member (Member *pElement)
{
    Member *pTemp = 0;
    if (Is_DB_full() == 0)
    {
        if (pElement == 0)
        {
            return 0;
        }
        else
        {
            if(pHead == 0)
            {
                if ((Create_DB(pElement)) == 1)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                pTemp = (Member *) malloc(sizeof(Member));

                if(pTemp == 0)
                {
                    return 0;
                }
                else
                {
                    memcpy(pTemp,pElement,sizeof(Member));
                    pTemp -> pNext = pHead ;
                    pHead = pTemp;

                    return 1;
                }
            }
        }
    }
    else
    {
        printf("\nThe Database is full !! \n");
    }
    return 0;
}

extern uint8_t Add_member_by_index(Member *pElement , uint32_t u32Index)
{
    Member *pTemp1 = 0;
    Member *pTemp2 = 0;
    Member *pMove = 0;
    Member *pPrevious_element = 0;
    uint8_t u8Tail_index = 0;
    uint8_t u8Move_index = 0;

    if(Is_DB_full() == 0)
    {
        if(pElement == 0 )
        {
            return 0;
        }
        else
        {
            if(pHead == 0 || u32Index == 0)
            {
                if (Add_head_member(pElement))
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                pMove = pHead ;
                u8Tail_index = 0 ;

                while (pMove -> pNext !=  0)
                {
                    pMove = pMove -> pNext;
                    u8Tail_index ++ ;
                }

                if (u32Index > (u8Tail_index +1))
                {
                    if (Add_tail_member(pElement) == 1)
                    {
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                }
                else
                {
                    pTemp1 = (Member *) malloc(sizeof(Member));
                    if (pTemp1 == 0)
                    {
                        return 0;
                    }
                    else
                    {
                        memcpy(pTemp1,pElement,sizeof(Member));
                        pMove = pHead ;
                        pPrevious_element = pHead ;

                        while (u8Move_index != (u32Index -1) )
                        {
                        pPrevious_element = pPrevious_element -> pNext ;
                        u8Move_index ++;
                        }
                        u8Move_index = 0;

                        while (u8Move_index != u32Index)
                        {
                            pMove = pMove -> pNext ;
                            u8Move_index ++;
                        }

                         pTemp2 = (Member *) malloc(sizeof(Member));
                        if (pTemp2 == 0)
                        {
                            return 0;
                        }

                        else
                        {
                            memcpy(pTemp2,pMove,sizeof(Member));
                        }

                        pMove = pTemp1;
                        pPrevious_element -> pNext = pMove ;
                        pMove -> pNext = pTemp2;
                        return 1;
                    }
                }
            }
        }
    }

    else
        {
            printf("\nThe Database is full ..!!\n");
        }

    return 0;
}

extern uint8_t Delete_head_member (void)
{
    Member *pTemp = 0;

    if (pHead == 0)
    {
        return 0 ;
    }
    else
    {
       pTemp = pHead -> pNext ;
       pHead = 0;
       free(pHead);
       pHead = pTemp;
       return 1;
    }
    return 0;
}

extern uint8_t Delete_tail_member (void)
{
    uint8_t u8Tail_index = 0 ;
    uint8_t u8Previous_index = 0;

    Member *pPrevious_to_tail = 0;
    Member *pMove = 0;

    if (pHead == 0)
    {
        return 0 ;
    }
    else
    {
        pMove = pHead ;
       while (pMove -> pNext != 0)
       {
           pMove = pMove -> pNext ;
           u8Tail_index ++ ;
       }
       if (u8Tail_index == 0)
       {
           Delete_head_member();
       }
       else
       {
           pPrevious_to_tail = pHead ;
           while (u8Previous_index !=  (u8Tail_index -1))
           {
               pPrevious_to_tail = pPrevious_to_tail -> pNext ;
               u8Previous_index ++;
           }
           free(pMove);
           pMove = 0;

           pPrevious_to_tail -> pNext = 0;
       }

       return 1;
    }
    return 0;
}

extern void Print_length_of_database (void)
{
    uint32_t u32Length = 1;
    Member *pMove = 0;

    pMove = pHead ;

    if (pHead == 0)
    {
        printf("The list is empty \n");
    }

    else
    {
        while (pMove -> pNext != 0)
        {
            pMove = pMove -> pNext ;
           (u32Length) ++;
        }
        printf("\nThe number of members in the database now is   %d\n\n",u32Length);
    }
}

extern uint8_t Delete_member_by_index ( uint32_t u32Index)
{
    Member *pMove2 = 0;
    Member *pPrevious_element = 0;
    uint8_t u8Tail_index = 0;
    uint8_t u8Move_index = 0;

    if(pHead == 0 )
    {
        printf("There is nothing to delete as the Database is already empty ..!! \n");
    }
    else
    {
        if(pHead -> pNext == 0 || u32Index == 0)
        {
            Delete_head_member();
            return 1;
        }
        else
        {
            pMove2 = pHead ;
            u8Tail_index = 0 ;

            while (pMove2 -> pNext !=  0)

            {
                pMove2 = pMove2 -> pNext;
                u8Tail_index ++ ;
            }

            if (u32Index >= (u8Tail_index ))
            {
                Delete_tail_member();
            }

            else
            {
                pPrevious_element = pHead ;
                u8Move_index = 0;

                while (u8Move_index != (u32Index -1) )
                {
                pPrevious_element = pPrevious_element -> pNext ;
                u8Move_index ++;
                }    //Now pMove1 points at the previous member

                pMove2 = pHead ;
                u8Move_index = 0;

                while (u8Move_index != u32Index+1)
                {
                    pMove2 = pMove2 -> pNext ;
                    u8Move_index ++;
                }    //Now pMove2 points at the next member

                pPrevious_element -> pNext = pMove2;
            }
        }
    }
    return 0;
}

extern uint8_t Is_DB_full(void)
{
    uint32_t u32Check = 0;
    Member *pMove = 0;

    pMove = pHead ;

    while (pMove -> pNext != 0)
    {
        pMove = pMove -> pNext ;
       (u32Check) ++;
    }

    if(u32Check >= DATABASE_LIMIT-1)
    {
        printf("\nThe database is full ..!! Try deleting any member to add another\n");
        return 1;
    }
    else
    {
        printf("The database has free members \n");
        return 0;
    }

}

extern uint8_t Delete_member_by_ID(char *pcID)
{
    uint8_t u8Index = 0;
    Member *pMove = 0;

    if (pHead == 0)
    {
        return 0;
    }
    else
    {
        pMove = pHead ;
       while (pMove != 0)
        {
            if (strncmp(pcID, pMove ->cStudent_ID , NUMBER_OF_ELEMENTS) == 0)
                {
                    Delete_member_by_index(u8Index);
                    return 1;
                }
            else
                {
                    /* Do nothing */
                }
            pMove = pMove -> pNext;
            u8Index ++;
        }
        return 1;
    }
    return 0;
}

extern void Print_member(uint32_t u32Index)
{
    uint8_t u8Count = 0;
    uint8_t u8Target_index = 0;
    Member *pMove = 0;

        pMove = pHead ;
       while (pMove != 0)
        {
            if (u32Index == u8Target_index)
                {
                    printf("** Member  %d    ---------- \n", u8Count);
                    printf("   Student's ID   :  %s  \n", pMove -> cStudent_ID);
                    printf("   Year of study  :  %d  \n", pMove -> u32Year_of_study);
                    printf("   Course1's ID   :  %s  \n", pMove -> ucCourse1_ID);
                    printf("   Course1's Grade:  %d  \n", pMove -> u32Course1_grade);
                    printf("   Course2's ID   :  %s  \n", pMove -> ucCourse2_ID);
                    printf("   Course2's Grade:  %d  \n", pMove -> u32Course2_grade );
                }
            else
                {
                    /* Do nothing */
                }
            pMove = pMove -> pNext;
            u8Count ++;
            u8Target_index ++;
        }
}

extern void Search_ID (char *pcID)
{
    uint8_t u8Index = 0;
    Member *pMove = 0;

        pMove = pHead ;
       while (pMove != 0)
        {
            if (strncmp(pcID, pMove ->cStudent_ID , NUMBER_OF_ELEMENTS) == 0)
                {
                    Print_member(u8Index);

                }
            else
                {
                    /* Do nothing */
                }
            pMove = pMove -> pNext;
            u8Index ++;
        }
}

extern void Sort_DB_grade1_ascend(void)
{
    Member *pMove1 = 0;
    Member *pMove2 = 0;
    Member *pTemp = 0;
    pTemp =(Member*) malloc(sizeof(Member));

    for(pMove1 = pHead; pMove1  != 0 ; pMove1 = pMove1 -> pNext)
    {
        for(pMove2 = pMove1; pMove2  != 0 ; pMove2 = pMove2 -> pNext)
        {
            if (pMove2 ->u32Course1_grade < pMove1 ->u32Course1_grade )
            {
                pTemp ->pNext = pMove1 ->pNext;
                pMove1 ->pNext = pMove2 ->pNext;
                pMove2 ->pNext = pTemp ->pNext;
            }
            else
            {

            }
        }
    }
}

extern uint8_t Get_free_member(Member *pElement[] , uint32_t *u32free_member)
{
    uint8_t u8Count = 0;

    for(u8Count = 0; u8Count < DATABASE_LIMIT ; u8Count++)
    {
        if (pElement[u8Count] == 0)
        {
            *u32free_member = u8Count ;
            return 1;
        }
        else
        {

        }
    }
    return 0;
}

extern uint8_t Get_deleted_head_member(Member *pElement[] , uint32_t *u32Deleted_element)
{
    uint8_t u8Count = 0;
    char u32Deleted_member[NUMBER_OF_ELEMENTS] = {0};

    strncpy(pHead ->cStudent_ID,u32Deleted_member,NUMBER_OF_ELEMENTS*sizeof(char));

    for (u8Count = 0; u8Count < DATABASE_LIMIT ; u8Count ++)
    {
        if (pElement[u8Count] ->cStudent_ID == u32Deleted_member)
        {
            *u32Deleted_element = u8Count ;
            return 1;
        }
        else
        {

        }
    }
    return 0;
}

extern uint8_t Get_deleted_tail_member(Member *pElement[] , uint32_t *u32Deleted_element)
{
    uint8_t u8Count = 0;
    char u32Deleted_member[NUMBER_OF_ELEMENTS] = {0};
    Member *pMove = 0;

    pMove = pHead ;
    while (pMove -> pNext != 0)
    {
        pMove = pMove -> pNext ;
    }

    strncpy(pMove ->cStudent_ID,u32Deleted_member,NUMBER_OF_ELEMENTS*sizeof(char));

    for (u8Count = 0; u8Count < DATABASE_LIMIT ; u8Count ++)
    {
        if (pElement[u8Count] ->cStudent_ID == u32Deleted_member)
        {
            *u32Deleted_element = u8Count ;
            return 1;
        }
        else
        {

        }
    }
    return 0;
}

extern uint8_t Get_indexed_deleted_member(Member *pElement[] ,uint32_t u32Index, uint32_t *u32Deleted_element)
{
    uint8_t u8Count = 0;
    uint8_t u8Move_index = 0;
    char u32Deleted_member[NUMBER_OF_ELEMENTS] = {0};
    Member *pMove = 0;


    pMove = pHead;
    while (u8Move_index != u32Index)
    {
        pMove = pMove ->pNext;
        u8Move_index ++;
    }

    strncpy(pMove ->cStudent_ID,u32Deleted_member,NUMBER_OF_ELEMENTS*sizeof(char));

    for (u8Count = 0; u8Count < DATABASE_LIMIT ; u8Count ++)
    {
        if (pElement[u8Count] ->cStudent_ID == u32Deleted_member)
        {
            *u32Deleted_element = u8Count ;
            return 1;
        }
        else
        {

        }
    }
    return 0;
}





