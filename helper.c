#include "monty.h"

/**
*
*/
void free_list(stack_t *head)
{
	stack_t *node;
	if (head != NULL)
	{
		node = head;
		if (node != NULL && node->next != NULL)
		{
			free_node(node->next);
		}
		free(head);
	}
}

/**
*
*/
void free_node(stack_t *node)
{
	if (node->next != NULL)
	{
		free_node(node->next);
	}
	free(node);
}
