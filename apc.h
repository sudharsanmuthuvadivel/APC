#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Project operation type
  ADDITION:
  op_sign_flag = 0 -> addition, 1 | 2 = sub,  3 = -addition 
  SUBSTRACTION:
  op_sign_flag = 0 -> sub, 1-> sub (if op1 > op2 = -), 2 -> add, 3 -> sub (if op1 > op2 = -)
  MULTIPLICATION :
  op_sign_flag = 0 -> mul, 1 or 2 -> mul (-), 3 -> mul (+)
  DIVISION:
  op_sign_flag = 0 ->div, 1 | 2 -> div (-), 3 -> div(+) */
typedef int data_t;
typedef long long int l_data_t;

extern data_t op_sign_flag; // flag used to find result is -ve or +ve
extern char g_operator;
extern char *str1;
extern char *str2;

//define MACROS
#define SUCCESS 0
#define FAILURE -1


/* Define macros for colours */
#define  RED  	 "\033[1;31m"
#define  GREEN	 "\033[1;32m"
#define  YELLOW	 "\033[1;33m"
#define  RESET	 "\033[0m"


//structure for doubly linkedlist
typedef struct node
{
	struct node *prev;
	data_t data;
	struct node *next;
}Dlist;

/* Function Prototypes*/

/*Function to validate input arguments and store the value in linked list*/
data_t input_validation(int argc, char **argv, Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2);

/*main Function to do addition operation*/
data_t apc_addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

/*Function to do substraction operation*/
data_t apc_subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

/*Function to do multiplication operation*/
data_t apc_multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

/*Function to do copy the list from another list*/
data_t copy_list(Dlist **dest, Dlist **source , Dlist **dest_tail);

/*Function to delete the list*/
data_t dl_delete_list(Dlist **head, Dlist **tail);

/*Function to do division operation*/
data_t apc_division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

/*function to find sum of all list element in the list*/
l_data_t sum_of_list(Dlist **head);

/*Function to print result*/
void print_result(Dlist *head);

/*Function to count element in the list*/
data_t count_of_element(Dlist *head);

/*Function to check which operand is big*/
data_t check_greater(Dlist **head1, Dlist **head2);

/*Function to insert the data in list last position*/
data_t insert_at_last(Dlist **head, Dlist **tail, int data);

/*Funtion to insert the data in the list at first position*/
data_t insert_at_first(Dlist **head, data_t data, Dlist **tail);

/*Reusable Function to add the two list element and store in anothe list*/
data_t addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

#endif
