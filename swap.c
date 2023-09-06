#include "monty.h"

/**
* swap - swaps the top two elements of the stack
* @stack: pointer to pointer to the top of the stack
* @line_number: the line number of the line read
*
* Return: void
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int temp;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: ", line_number);
		fprintf(stderr, "can't swap, stack too short\n");
		exit(EXIT_FAILURE);
	}
	temp = current->n;
	current->n = current->next->n;
	current->next->n = temp;
}
