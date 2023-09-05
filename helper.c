#include "monty.h"

/**
* free_stack - frees the stack_t stack
* @stack: stack that is freed
*
* Return: void
*/
void free_stack(stack_t *stack)
{
	stack_t *next_stack;

	while (stack != NULL)
	{
		next_stack = stack->next;
		free(stack);
		stack = next_stack;
	}
}
