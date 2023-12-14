#include "monty.h"
/**
 * execute - Executes the opcode
 * @line: Line content from Monty file
 * @stack: Pointer to the head of the stack
 * @line_number: Line number in the Monty file
 * @file: Pointer to the Monty file
 * Return: 0 on success, 1 on failure
 */

int execute(char *line, stack_t **stack, unsigned int line_number, FILE *file)
{
    instruction_t opcodes[] = {
        {"push", push},
        {"pop", pop}, 
        {"stack", f_stack},
        {"printStack", printStack},
        {"printTopElemnt", print_top},
        {"rotateBottomElmnt", rotateStackBottomToTop},
        {"rotateTopElmnt", rotateStackTopToBottom},
        {"printStringFromTop", printStringFromTop},
        {"printCharFromTop",  printCharFromTop},
        {"add", add},
        {NULL, NULL}
    };

    unsigned int opcode_index = 0;
    char *opcode;

    opcode = strtok(line, " \n\t");
    if (opcode && opcode[0] == '#')
        return (0);

    bus.arg = strtok(NULL, " \n\t");

    while (opcodes[opcode_index].opcode && opcode)
    {
        if (strcmp(opcode, opcodes[opcode_index].opcode) == 0)
        {
            opcodes[opcode_index].f(stack, line_number);
            return (0);
        }
        opcode_index++;
    }

    if (opcode && opcodes[opcode_index].opcode == NULL)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
        fclose(file);
        free(line);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    return (1);
}
