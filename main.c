/**************************************************************************************************************************************************************
 *Title		    : Arbitrary Precision Calculator (APC)
 *Author        : SUDHARSAN M
 *Date          : 21.10.2024
 *Description	: The goal of this calculator project in C is to implement basic mathematical operations 
                  for two large numbers using big-num arithmetic.
 ***************************************************************************************************************************************************************/
#include "apc.h"

/*Driver function for the all the functions*/
int main(int argc, char *argv[])
{
	Dlist *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL, *headR = NULL, *tailR = NULL;
	char operator;

	if (input_validation(argc, argv, &head1, &tail1, &head2, &tail2) == FAILURE)
	{
		printf(RED"ERROR: Failed to store operands in linked list\n"RESET);
		printf(GREEN"\nUSAGE: ./a.out operand1 operator operand2\nExample...\n"RESET);
		printf(YELLOW"ADDITION:\n operand1 + operand2\nSUBSTRACTION:\n operand1 - operand2\n");
		printf("MULTIPLICATION:\n operand1 '*' operand2\nSUBTRACTION:\n operand1 / operand2\n"RESET);
		return 1;
	}
	operator= argv[2][0];

	switch (operator)
	{
	case '+':
		/* call the function to perform the addition operation */
		apc_addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
		break;
	case '-':
		/* call the function to perform the subtraction operation */
		apc_subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
		break;
	case '*':
		/* call the function to perform the multiplication operation */
		apc_multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
		break;
	case '/':
		/* call the function to perform the division operation */
		apc_division(&head1, &tail1, &head2, &tail2, &headR, &tailR);
		break;
	default:
		printf(RED"ERROR: Invalid Input: Try again...\n"RESET);
	}

	//Function call to free the memory
	dl_delete_list(&head1, &tail1);
	dl_delete_list(&head2, &tail2);
	dl_delete_list(&headR, &tailR);
	return 0;
}
