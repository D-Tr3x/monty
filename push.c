#include "monty.h"

/**
 * push - pushes an integer to the stack
 * @stack: double pointer to top of the stack
 * @line_number: the current line number in bytecode
 * @arg: argument to push
 */
void push(stack_t **stack, unsigned int line_number)
{
    stack_t *node;
    int current;

    if (argt == NULL || (*argt != '-' && !isdigit(*argt)))
    {
        fprintf(stderr, "L%u: usage: push integer", line_number);
        exit(EXIT_FAILURE);
    }

    current = atoi(argt);

    node = malloc(sizeof(stack_t));
    if (node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    node->n = current;
    node->prev = NULL;
    node->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = node;
    *stack = node;
}
