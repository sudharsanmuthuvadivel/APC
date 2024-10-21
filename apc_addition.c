
#include "apc.h"
/*main Function to do addition operation
Input : operand1 list(head1, tail1), operand2 list(head2, tail2), result list(headR, tailR)
Output : SUCCESS, FAILURE
*/
data_t apc_addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	//check if operand 1 or 2 having a -ve sign, do substraction
	if((g_operator == '+') && (op_sign_flag == 1 || op_sign_flag == 2))
	{
		apc_subtraction(head1, tail1, head2, tail2, headR, tailR);//function call to do substraction
		return SUCCESS;
	}

	data_t result = addition(head1, tail1, head2, tail2, headR, tailR); //function call to add two list data
	if(result == FAILURE)
	{
		printf("ERROR: Addition function failed\n");
		return FAILURE;
	}

	//print result in -v , when both operand are -ve or operand1 is -ve and operator is '-'
	if((op_sign_flag == 3 && g_operator == '+') || (g_operator == '-' && op_sign_flag == 1))
	{
		printf(GREEN"\n\tRESULT = -"RESET);
		print_result(*headR); //function call to print the result
	}
	else 
	{
		printf(GREEN"\n\tRESULT = "RESET);
		print_result(*headR);
	}
	return SUCCESS;
}
