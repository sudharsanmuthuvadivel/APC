
#include "apc.h"

/*Function to multiply two list data and store on another list */
data_t apc_multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **res1, Dlist **r1_tail)
{
	data_t carry = 0, count = 0;
	Dlist *temp1 = *tail1, *temp2 = *tail2, *res2 = NULL, *r2_tail = NULL, *res3 = NULL, *r3_tail = NULL;

	while (temp2) //multiplier(list2)
	{

		for (int i = 0; i < count; i++)
			insert_at_first(res1, 0, r1_tail); //function call to add 0
		while (temp1) //multiplicand (list1)
		{
			int mul = (temp1->data * temp2->data) + carry;
			carry = mul / 10;
			insert_at_first(res1, mul % 10, r1_tail);
			temp1 = temp1->prev;
		}
		if (carry) //check if carry present at last, insert to list.
		{
			insert_at_first(res1, carry, r1_tail);
			carry = 0; // Reset carry for next iteration
		}
		
		if (!res2)
			copy_list(&res3, res1, &r3_tail); //function call to copy res1 list data to res3 list
		else
			//function call to add the list datas
			addition(res1, r1_tail, &res2, &r2_tail, &res3, &r3_tail);
	
		dl_delete_list(res1, r1_tail); //function call to delete the list 
		dl_delete_list(&res2, &r2_tail);
		
		if (!temp2->prev)//multiplier reach NULL print result
		{
			//print result as -ve, if operand 1 or 2 is -ve
			if(op_sign_flag == 2 || op_sign_flag == 1)
				printf(GREEN"\n\tRESULT = -"RESET);
			else
				printf(GREEN"\n\tRESULT = "RESET);
			print_result(res3); //function call to print result
			return SUCCESS;
		}

		copy_list(&res2, &res3, &r2_tail);//function call to copy the res3 list value to res2 list.
		
		dl_delete_list(&res3, &r3_tail); //function call to delete the list.

		temp2 = temp2->prev; //move to next node
		temp1 = *tail1;  
		count++;   //count increment
	}
	return SUCCESS;
}

/*Function to copy the list data to another list*/
data_t copy_list(Dlist **dest, Dlist **source, Dlist **dest_tail)
{
	Dlist *temp = *source;
	while (temp)
	{
		insert_at_last(dest, dest_tail, temp->data); //function call to insert the data at last node of the list
		temp = temp->next; //move to next node
	}
	
	return SUCCESS;
}

/*Function to delete entire list */
data_t dl_delete_list(Dlist **head, Dlist **tail)
{
	if (*tail == NULL) // Check if the list is already empty
		return FAILURE;

	while (*tail != NULL) // Traverse and delete each node
	{
		if ((*tail)->prev == NULL) // Only one node in the list
		{
			free(*tail);  // Free the only node
			*head = NULL; // Set both head and tail to NULL
			*tail = NULL;
		}
		else
		{
			*tail = (*tail)->prev; // Move tail to the previous node
			free((*tail)->next);   // Free the last node
			(*tail)->next = NULL;  // Set the next pointer of the previous node to NULL
		}
	}
	return SUCCESS;
}

