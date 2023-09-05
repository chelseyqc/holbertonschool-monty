#include "monty.h"

/**
*
*/
void push(stack_t **head, unsigned int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		free_list(*head);
		exit(98);
	}
	new_node->n = n;
	if (*head == NULL)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		*head = new_node;
	}
	else
	{
		new_node->next = *head;
		(*head)->prev = new_node;
		*head = new_node;
	}
}
