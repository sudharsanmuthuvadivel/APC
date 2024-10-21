#include "apc.h"

/*
Function to validate input arguments and store the value in linked list.
Input : argument count, argument vector, operand1 list(head1, tail1), operand2 list(head2, tail2)
Output : SUCCESS, FAILURE
*/
/*extern variable*/
data_t op_sign_flag;
char *str1, *str2, g_operator;
data_t input_validation(int argc, char **argv, Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2)
{
    str1 = argv[1];
    str2 = argv[3];
    g_operator = argv[2][0];
    int op1_sign = 0, op2_sign = 0;
    if (argc == 4)  //check if argument count is 4
    {
        for (data_t i = 1; i < argc; i++)
        {
            if (i == 2)  //skip argument 2
                continue;
            if (argv[i] != NULL) //check if argument is present or not
            {
                data_t j = 0;
                while (argv[i][j] != '\0')
                {
                    //find operand sign
                    if(argv[1][0] == '-') 
                        op1_sign = 1;
                    if(argv[3][0] == '-')
                        op2_sign = 1;
                    if (argv[i][j] >= '0' && argv[i][j] <= '9') //check if value between 0 to 9
                    {
                        if (i == 1)
                        {   //add operand1 value in list1 in double linked list format
                            if (insert_at_last(head1, tail1, argv[i][j] - '0') != SUCCESS)
                            {
                                printf("ERROR: Failed to store operand 1 in linked list\n");
                                return FAILURE;
                            }
                        }
                        else
                        {   //add operand2 value in list1 in double linked list format
                            if (insert_at_last(head2, tail2, argv[i][j] - '0') != SUCCESS)
                            {
                                printf("ERROR: Failed to store operand 2 in linked list\n");
                                return FAILURE;
                            }
                        }
                    }
                    j++;
                }
            }
            else{
                printf("argv[%d] not found\n", i);
                return FAILURE;
            }
        }
        //find which operand has a -ve sign
        if(!op1_sign && !op2_sign)
            op_sign_flag = 0;
        else if(op1_sign && !op2_sign)
            op_sign_flag = 1;
        else if (!op1_sign && op2_sign)
            op_sign_flag = 2;
        else
            op_sign_flag = 3;
        return SUCCESS;
    }
    // printf("argc = %d\n", argc);
    // printf("argc not 4\n");
    return FAILURE;
}
