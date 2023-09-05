#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void run_cmd(FILE *fp, int line, char *o, instruction_t *ops, stack_t **stack);
void threecrabs(FILE *fp, char *o, stack_t **stack);
int is_valid_cmd(char *cmd, instruction_t *opcodes);
int is_valid_val(char *val);
void push(stack_t **head, unsigned int n);
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void free_list(stack_t *head);
void free_node(stack_t *node);

#endif
