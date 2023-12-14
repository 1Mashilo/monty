
#include "monty.h"

/**
 * addTopTwoElements - Adds the top two elements of the stack.
 * @head: Stack head
 * @counter: Line number
 * Return: No return
 */
void add(stack_t **head, unsigned int counter)
{
    stack_t *current;
    int stackSize = 0, sum;
    current = *head;

    while (current)
    {
        current = current->next;
        stackSize++;
    }

    if (stackSize < 2)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    current = *head;
    sum = current->value + current->next->value;

    current->next->value = sum;

    *head = current->next;
    free(current);
}
