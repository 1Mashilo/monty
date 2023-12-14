#include "monty.h"

/**
 * monty_pall - Prints the entire contents of the stack.
 *
 * @head: Pointer to the head node of the stack.
 * @counter: Line number where the `pall` opcode was encountered (unused).
 *
 * Returns: None (void).
 *
 * This function iterates through the stack and prints the data
 * stored in each node to the standard output, one element per line.
 * If the stack is empty, it simply returns without printing anything.
 */

void monty_pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}