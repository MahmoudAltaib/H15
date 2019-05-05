#include "Database.h"

static Member *pStudent[DATABASE_LIMIT] = {0};

int main(void)
{
    uint32_t u32Repeat_operation = 0;
    uint32_t u32Choose_operation = 0;
    uint32_t u32free_element = 0;
    uint32_t u32Deleted_member = 0;
    uint32_t u32Index = 0;
    char cStudent_ID[NUMBER_OF_ELEMENTS] = {0};

    do
    {
        printf("Hi!! Please choose one of the upcoming operation  :  \n\n");
        printf("1) Create database\n") ;
        printf("2) Add head member to the database \n") ;
        printf("3) Add tail member to the database \n") ;
        printf("4) Add member by index to the database  \n") ;
        printf("5) Delete head member from the database \n") ;
        printf("6) Delete tail member from the database \n") ;
        printf("7) Delete member by index from the database\n") ;
        printf("8) Print the database\n") ;
        printf("9) Print member by index\n") ;
        printf("10) Search for a member by ID\n") ;
        printf("11) Print number of entries in the database ID\n") ;
        printf("12) Check if the database is full or not \n\n") ;

        scanf("%d",&u32Choose_operation);

        if (u32Choose_operation == OP1)  /* OP1 is a member of an enumeration representing one of the operations*/
        {
            pStudent[u32free_element] = (Member *) malloc(sizeof(Member));
            Get_student_info(pStudent[0]);
            Create_DB(pStudent[0]);
            Print_DB();
            Print_length_of_database();
        }

        else if (u32Choose_operation == OP2)
        {
            Get_free_member(pStudent , &u32free_element);
            pStudent[u32free_element] = (Member *) malloc(sizeof(Member));
            Get_student_info(pStudent[u32free_element]);
            Add_head_member(pStudent[u32free_element]);
            Print_DB();
            Print_length_of_database();
        }

        else if (u32Choose_operation == OP3)
        {
            Get_free_member(pStudent , &u32free_element);
            pStudent[u32free_element] = (Member *) malloc(sizeof(Member));
            Get_student_info(pStudent[u32free_element]);
            Add_tail_member(pStudent[u32free_element]);
            Print_DB();
            Print_length_of_database();
        }

        else if (u32Choose_operation == OP4)
        {
            printf("Enter the index you want   :   ");
            scanf("%d", &u32Index);

            Get_free_member(pStudent , &u32free_element);
            pStudent[u32free_element] = (Member *) malloc(sizeof(Member));
            Get_student_info(pStudent[u32free_element]);
            Add_member_by_index(pStudent[u32free_element],u32Index);
            Print_DB();
            Print_length_of_database();
        }

        else if (u32Choose_operation == OP5)
        {
            Get_deleted_head_member(pStudent , &u32Deleted_member);
            Delete_head_member();
            free(pStudent[u32Deleted_member]);
            pStudent[u32Deleted_member] = 0;
            Print_DB();
            Print_length_of_database();
        }

        else if (u32Choose_operation == OP6)
        {
            Get_deleted_tail_member(pStudent , &u32Deleted_member);
            Delete_tail_member();
            free(pStudent[u32Deleted_member]);
            pStudent[u32Deleted_member] = 0;
            Print_DB();
            Print_length_of_database();
        }

        else if (u32Choose_operation == OP7)
        {
            printf("Enter the index you want   :   ");
            scanf("%d", &u32Index);

            Get_indexed_deleted_member(pStudent , u32Index ,&u32Deleted_member );
            Delete_member_by_index(u32Index);
            free(pStudent[u32Deleted_member]);
            pStudent[u32Deleted_member] = 0;
            Print_DB();
            Print_length_of_database();
        }

        else if (u32Choose_operation == OP8)
        {
            Print_DB();
        }

        else if (u32Choose_operation == OP9)
        {
            printf("Enter the index you want   :   ");
            scanf("%d", &u32Index);

            Print_member(u32Index);
        }

        else if (u32Choose_operation == OP10)
        {
            printf("Enter the wanted ID   :    ");
            scanf("%s", cStudent_ID);

            Search_ID(cStudent_ID);
        }

        else if (u32Choose_operation == OP11)
        {
            Print_length_of_database();
        }

        else if (u32Choose_operation == OP12)
        {
            Is_DB_full();
        }

        else
        {
            printf("Wrong choice please try one of the previous choices \n ");
        }

        printf("Do you want to continue !?   (Enter any number to continue , enter 0 to quit .. !!)\n");
        scanf("%d",&u32Repeat_operation);
    }while (u32Repeat_operation != 0);

}
