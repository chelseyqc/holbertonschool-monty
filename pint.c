#include "monty.h"

/**
* pint - prints the value at the top of the stack, followed by a new line
* @stack: pointer to pointer to the stack in the stack_t struct
* @line_number: line number of the command read
*
* Return: void
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%i\n", (*stack)->n);
}
