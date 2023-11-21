#include "monty.h"

/**
 * rotate_stack - Rotates the stack, moving the top element to the bottom
 * @head: Pointer to the head of the stack
 * @counter: Line number in the Monty file (unused in this function)
 */
void rotateStackTopToBottom(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *copy;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}

/**
 * rotateStackBottomToTop - Rotates the stack, moving the bottom element to the top
 * @head: Pointer to the head of the stack
 * @counter: Line number (unused in this function)
 */
void rotateStackBottomToTop(stack_t **head, __attribute__((unused)) unsigned int counter)
{
    stack_t *tmp = *head, *aux;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	aux = (*head)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux;
}
