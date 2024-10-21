#include "apc.h"

/*Function to count number of element in the list
Input : List head
Output : count*/
data_t count_of_element(Dlist *head)
{
    int count = 0;
    Dlist *temp = head, *prev = NULL;
    while (temp)
    {
        if (!temp->data)
        {
            if (!prev || !prev->data)//skip zeros at begining of the list
            {
                prev = temp;
                temp = temp->next; // Skip this node if conditions are met
            }
            else
            {
                count++; // Increment count1 for other nodes
                prev = temp;
                temp = temp->next; // Move to the next node
            }
        }
        else
        {
            count++; // Increment count1 for other nodes
            prev = temp;
            temp = temp->next; // Move to the next node
        }
    }
    return count;
}
/*Function to find which operand is bigger
Input : head of list1, head of list2
Output : flag */
data_t check_greater(Dlist **head1, Dlist **head2)
{
    int flag = 0, count1 = 0, count2 = 0;
    Dlist *temp = *head1, *prev = NULL;
    count1 = count_of_element(*head1);//function call to find number of element in list
    count2 = count_of_element(*head2);

    

    if (count1 == count2) //if both list count is same
    {  
         /*logic to find which value is high*/
        Dlist *t1 = *head1, *t2 = *head2;
        while(t1)
        {
            if(t1->data > t2->data)
                return 1;
            else if(t1->data < t2->data)
                return -1;
            
            t1 = t1->next;
            t2 = t2->next;
        }
        if(!t1 && !t2)
            return 0;
    }
    else
        flag = (count1 > count2) ? 1 : -1; //incase count not same
    
    return flag;
}

/*Function to insert the data at last of the list*/
data_t insert_at_last(Dlist **head, Dlist **tail, data_t data)
{
    Dlist *new = malloc(sizeof(Dlist)); //allocate memory in head segment
    if (!new)
        return FAILURE;

    new->data = data;
    new->next = NULL;
    new->prev = NULL;

    if (!*head) //assign head to new node , if list is empty
    {
        *head = new;
        *tail = new;
        return SUCCESS;
    }
    //if list not empty update node links and tail
    new->prev = *tail;
    (*tail)->next = new;
    *tail = new;
    return SUCCESS;
}

/*Function to insert the data at starting point of the list*/
data_t insert_at_first(Dlist **head, data_t data, Dlist **tail)
{

    Dlist *new = malloc(sizeof(Dlist));//allocate memory in heap
    if (!new)
        return FAILURE;

    new->data = data;
    new->next = NULL;
    new->prev = NULL;

    if (!*head)//check if list is empty, update head and tail with new
    {
        *head = new;
        *tail = new;
        // printf("Function done!\n");
        return SUCCESS;
    }
    //incase list not empty, update head and new node link
    new->next = *head;
    (*head)->prev = new;
    *head = new;
    // printf("Function done!\n");
    return SUCCESS;
}

//Function to add value in list and store to the another list
data_t addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	data_t carry = 0, num1, num2, sum = 0;
	Dlist *temp1 = *tail1, *temp2 = *tail2;

	while (temp1 || temp2)//run the until both list reach NULL
	{
        num1 = temp1 ? temp1->data : 0;
		
        num2 = temp2 ? temp2->data : 0;
		
		sum = num1 + num2 + carry; 
		carry = sum / 10;		   
		insert_at_first(headR, sum % 10, tailR);//function call to insert the data at first node

		if (temp1) //check if node not NULL , move to next node
			temp1 = temp1->prev;
		if (temp2)
			temp2 = temp2->prev;
	}
	if (carry) //after addition if caary present add to list
	{
		insert_at_first(headR, carry, tailR);
		carry = 0; // Reset carry
	}
	return SUCCESS;
}

//Funtion to print the result of arithemetic operation
void print_result(Dlist *head)
{
    Dlist *temp = NULL;
    /* Cheking the list is empty or not */
    if (head == NULL)
        printf(GREEN"0\n"RESET);
    else
    {
        while (head)
        {
            /*check condition to avoid contious zeros in MSB*/
            if ((!head->data && !temp) || (!head->data && !temp->data))
            {
                temp = head;
                head = head->next;
                if(!head)  //check full list is zero print single 0 as a result.
                    printf(GREEN"0"RESET);
            }
            else
            {
                /* Printing the list */
                printf(GREEN"%d"RESET, head->data);
                temp = head;
                /* Travering in forward direction */
                head = head->next;
            }
        }
        printf("\n");
    }
    return;
}