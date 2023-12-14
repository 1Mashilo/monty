#include "monty.h"

/**
 * stack - Set stack mode by updating the lifo flag
 * @stack: Pointer to the head of the stack
 * @line_number: Line number in the Monty file
 */
void f_stack(stack_t **stack, unsigned int line_number)
{
    (void)stack; 

    bus.lifo_mode = 0;
    (void)line_number; 
}

/**
 * pall - Prints the stack
 * @stack: Pointer to the head of the stack
 * @line_number: Line number in the Monty file (unused)
 * Return: No return
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current_node;
    (void)line_number;

    current_node = *stack;

    if (current_node == NULL)
        return;

    while (current_node)
    {
        printf("%d\n", current_node->value);
        current_node = current_node->next;
    }
}

/**
 * print_top - prints the top element of the stack
 * @head: pointer to the head of the stack
 * @counter: line number
 * Return: no return
 */
void print_top(stack_t **head, unsigned int counter)
{
    if (*head == NULL)
    {
        fprintf(stderr, "L%u: can't print top element, stack empty\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*head)->value);
}

/**
 * printStringFromTop - Prints the string starting at the top of the stack,
 * followed by a new line
 * @stack: Pointer to the head of the stack
 * @line_number: Line number in the Monty file
 * Return: No return
 */
void printStringFromTop(stack_t **stack, unsigned int line_number)
{
    stack_t *current_node;
    (void)line_number;

    current_node = *stack;

    while (current_node)
    {
        if (current_node->value > 127 || current_node->value <= 0)
        {
            break;
        }
        printf("%c", current_node->value);
        current_node = current_node->next;
    }
    printf("\n");
}

/**
 * printCharFromTop - Prints the character at the top of the stack, followed by a newline
 * @stack: Pointer to the head of the stack
 * @line_number: Line number in the Monty file
 * Return: No return
 */
void printCharFromTop(stack_t **stack, unsigned int line_number)
{
    stack_t *top;

    top = *stack;


    if (!top)
    {
        fprintf(stderr, "L%d: can't print char, stack empty\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    if (top->value > 127 || top->value < 0)
    {
        fprintf(stderr, "L%d: can't print char, value out of range\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    printf("%c\n", top->value);
}
