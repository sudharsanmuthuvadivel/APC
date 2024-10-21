
#include "apc.h"

/*Function to Divide operand1 by operand2 and store result in another list*/
data_t apc_division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	data_t ret = check_greater(head1, head2); //Function call to find which operand is bigger
	if (ret == 0)
	{
		//print result as -ve if any one operand is -ve
		(op_sign_flag == 1 || op_sign_flag == 2)? printf(GREEN"\n\tRESULT = -1\n"RESET) : printf(GREEN"\n\tRESULT = 1\n"RESET);	
		return SUCCESS;
	}
	else if (ret < 0) //print result as 0 , when operand1 < operand2
	{
		printf(GREEN"\n\tRESULT = 0\n"RESET);
		return SUCCESS;
	}

	l_data_t count = 0;
	l_data_t dividend = 0, divisor = 0;
	dividend = sum_of_list(head1); //function call to find sum od list
	divisor = sum_of_list(head2);
	//printf("Dividend = %llu, Divisor = %llu\n", dividend, divisor);
	
	if(divisor == 0) //check if divisor 0, print infinity
	{
		printf(GREEN"\n\tRESULT = undefined or infinity\n"RESET);
		return SUCCESS;
	}
	if(dividend == 0) //check if dividend is 0 print result as 0
	{
		printf(GREEN"\n\tRESULT = 0\n"RESET);
		return SUCCESS;
	}
	while (dividend > 0)//until dividend reach 0, substract divident by divisor
	{
		dividend -= divisor;
		count++; //count increment
	}
	if(op_sign_flag == 1 || op_sign_flag == 2) //print -ve if any one operand is -ve
		printf(GREEN"\n\tRESULT = -"RESET);
	else
		printf(GREEN"\n\tRESULT = "RESET);
	printf(GREEN"%llu\n"RESET, count); 
	return SUCCESS;
}

/*Function to find sum of list values*/
l_data_t sum_of_list(Dlist **head)
{
	l_data_t sum = 0;
	Dlist *temp = *head;
	while(temp) //loop run until temp reach NULL
	{
		sum = (sum*10) + temp->data; 
		temp = temp->next; 
	}
	return sum; //return value
}
