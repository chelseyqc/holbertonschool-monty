#include "monty.h"

/**
* main - the monty code
* @argc: the number of arguments
* @argv: argument vector
*
* Return: always 0
*/
int main(int argc, char **argv)
{
	FILE *fp = NULL;
	stack_t *stack = NULL;
	char *s;
	int bufsize = 65535, line = 1;
	char *buffer;

	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	buffer = malloc(sizeof(char) * bufsize);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	s = fgets(buffer, bufsize, fp);
	while (s != NULL)
	{
		run_cmd(fp, line, s, ops, &stack);
		s = fgets(buffer, bufsize, fp);
		line = line + 1;
	}
	free_list(stack);
	free(buffer);
	fclose(fp);
	return (0);
}
/**
* run_cmd - runs the command on the line
* @fp: file pointer
* @line: the line number of the command run
* @o: the line with the command
* @ops: array for the pointer functions
* @stack: the stack
*
* Return: void
*/
void run_cmd(FILE *fp, int line, char *o, instruction_t *ops, stack_t **stack)
{
	int i, value;
	char *cmd, *val;

	i = 0;
	if (o != NULL && o[0] == '$')
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, o);
		threecrabs(fp, o, stack);
	}
	cmd = strtok(o, " $");
	if (cmd != NULL)
	{
		cmd[strcspn(cmd, "\r\n")] = 0;
	}
	if (is_valid_cmd(cmd, ops) == 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, o);
		threecrabs(fp, o, stack);
	}
	value = line;
	if (strcmp(cmd, "push") == 0)
	{
		val = strtok(NULL, " ");
		if ((val == NULL) ||
				(strlen(val) == 0) || (is_valid_val(val) == 0))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line);
			threecrabs(fp, o, stack);
		}
		value = atoi(val);
	}
	while (ops[i].opcode != NULL)
	{
		if (strcmp(ops[i].opcode, cmd) == 0)
		{
			ops[i].f(stack, value);
			return;
		}
		i = i + 1;
	}
}

/**
* threecrabs - is kill
* @fp: file pointer
* @o: the string for the line
* @stack: the stack
*
* Return: void
*/
void threecrabs(FILE *fp, char *o, stack_t **stack)
{
	free(o);
	free_list(*stack);
	fclose(fp);
	exit(EXIT_FAILURE);
}

/**
* is_valid_cmd - checks if the command is valid
* @c: the command to check
* @opcodes: the valid opcodes
*
* Return: 1 if valid, else
*/
int is_valid_cmd(char *cmd, instruction_t *opcodes)
{
	int i;

	if (cmd == NULL)
	{
		return (0);
	}
	i = 0;
	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(opcodes[i].opcode, cmd) == 0)
		{
			return (1);
		}
		i = i + 1;
	}
	return (0);
}

/**
* is_valid_val - checks if the value is valid
* @val: the value to check
*
* Return: 0 if not a digit, else 1
*/
int is_valid_val(char *val)
{
	int i;

	i = 0;
	val[strcspn(val, "\r\n")] = 0;
	while (val[i] != '\0')
	{
		if (i == 0 && val[i] == '-')
		{
			i = i + 1;
			continue;
		}
		if ((val[i] >= 48 && val[i] <= 57))
		{
			return (1);
		}
		i = i + 1;
	}
	return (0);
}
