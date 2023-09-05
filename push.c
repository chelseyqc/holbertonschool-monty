#include "monty.h"

/**
* push - pushes a new node to the top of the stack
* @stack: pointer to pointer to the top of the stack
* @line_number: line number of the line read
*
* Return: void
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	char *token;
	int value;

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	token = strtok(NULL, " \t\r\n'$'");
	if (token == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = atoi(token);
	if (strspn(token, "0123456789+-") != strlen(token))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
