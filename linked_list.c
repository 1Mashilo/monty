#include "monty.h"

/**
 * addnode - Add a new node to the top of the stack
 * @head: Pointer to the head of the stack
 * @value: Value to be stored in the new node
 */
void addnode(stack_t **head, int value)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    new_node->value = value;
    new_node->prev = NULL;
    new_node->next = *head; // Set the next pointer to the current top of the stack

    if (*head != NULL)
    {
        (*head)->prev = new_node; // Update the previous pointer of the old top
    }

    *head = new_node; // Set the new node as the top of the stack
}
