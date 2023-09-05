#include "monty.h"

/**
* pop - removes the top element of the stack
* @stack: pointer to pointer to the top of the stack
* @line_number: the line number of the line read
*
* Return: void
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "can't pop an empty stack\n'");
		exit(EXIT_FAILURE);
	}
	if (stack != NULL)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}
