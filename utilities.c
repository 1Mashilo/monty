#include "monty.h"


/**
* free_stack - frees a doubly linked list
* @head_node: head of the stack
*/
void free_stack(stack_t *head)
{
	stack_t *next_node;

	next_node = head;
	while (head)
	{
		next_node = head->next;
		free(head);
		head = next_node;
	}
}