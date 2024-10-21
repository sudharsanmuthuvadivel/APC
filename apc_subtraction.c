
#include "apc.h"

/*Function to do substraction of two larger number and store result in resultant list*/
data_t apc_subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	//call addition function when operator is '-' and any one flag is -ve.
	if((g_operator == '-') && (op_sign_flag == 1 || op_sign_flag == 2))
	{
		apc_addition(head1, tail1, head2, tail2, headR, tailR);
		return SUCCESS;
	}
	int ret = check_greater(head1, head2); //function call to find which operand is bigger
	if(ret == 0)
	{
		printf(GREEN"\n\tRESULT = 0\n"RESET);
		return SUCCESS;
	}
	Dlist *temp1, *temp2;
	if(ret < 0)  //swap the list if operand1 < operand2
	{
		temp1 = *head1;
		*head1 = *head2;
		*head2 = temp1;
		temp1 = *tail1;
		*tail1 = *tail2;
		*tail2 = temp1;
	} 
	
	temp1 = *tail1, temp2 = *tail2;
	data_t num1, num2, borrow = 0;
	//logic for substraction
	while(temp1 || temp2) //loop will run until both pointer reches NULL
	{
		num1 = temp1 ? temp1->data : 0;
		
		num2 = temp2 ? temp2->data : 0;
		if(borrow)
		{
			num1 -= 1;
			borrow = 0;
		}
		if(num1 < num2)
		{
			num1 += 10;
			borrow = 1;
		}
		else
			borrow = 0;
		
		int sub = num1 - num2;
		insert_at_first(headR, sub , tailR);
		if(temp1)//if node not null move to previous node
			temp1 = temp1->prev;
		if(temp2)
			temp2 = temp2->prev;
	}
	if(ret < 0 && op_sign_flag != 1) // print -ve, when operand2 > operand1 and operand2 is -ve
		printf(GREEN"\n\tRESULT = -"RESET);
	else if((ret < 0 && op_sign_flag == 2) || (ret > 0 && op_sign_flag == 1) || (g_operator == '-' && op_sign_flag ==3))
		printf(GREEN"\n\tRESULT = -"RESET);
	else
		printf(GREEN"\n\tRESULT = "RESET);
	print_result(*headR); //function call to printf the result
	return SUCCESS;
}
