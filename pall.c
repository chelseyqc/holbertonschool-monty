#include "monty.h"

/**
* pall
*
*/
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *current;

	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
