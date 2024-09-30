#include "monty.h"

/**
 * pall - prints all the values on the stack, starting from the top of the stack
 * @stack: double pointer to top of the stack
 * @line_number: (unused)the current line in the bytecode file
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;
    (void)line_number;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
