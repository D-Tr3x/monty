#include "monty.h"
/**
 * free_stack - frees a stack
 * @stack: pointer to stack to be freed
 */
void free_stack(stack_t *stack)
{
  stack_t *temp;

  while (stack != NULL)
  {
    temp = stack;
    stack = stack->next;
    free(temp);
  }
}
