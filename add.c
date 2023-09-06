#include "monty.h"

/**
* add - adds top two elements of the stack, the top element contains the result
* and the stack is one element shorter
* @stack: pointer to pointer to the top of the stack
* @line_number: the line number of the line read
*
* Return: void
*/
void add(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "can't add, stack too short\n");
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "can't add, stack too short\n");
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n + (*stack)->n;
	pop(stack, line_number);
}
