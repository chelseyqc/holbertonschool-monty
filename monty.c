#include "monty.h"

/**
* main - the monty code
* @argc: the number of arguments
* @argv: argument vector
*
* Return: success if read monty, else failure
*/
int main(int argc, char *argv[])
{
	FILE *fp;
	stack_t *stack = NULL;
	ssize_t read;
	size_t len = 0;
	char *opcode, *line = NULL;
	unsigned int line_number = 1;

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
	read = getline(&line, &len, fp);
	while (read != -1)
	{
		opcode = strtok(line, " \t\r\n'$'");
		if (opcode == NULL)
		{
			line_number = line_number + 1;
			read = getline(&line, &len, fp);
			continue;
		}
		run_cmd(opcode, &stack, line_number);
		read = getline(&line, &len, fp);
		line_number = line_number + 1;
	}
	free(line);
	free_stack(stack);
	fclose(fp);
	return (EXIT_SUCCESS);
}
/**
* run_cmd - runs the command on the line
* @opcode: pointer to the opcode inputted
* @stack: pointer to top of the stack
* @line_number: line number of the line read
*
* Return: void
*/
void run_cmd(char *opcode, stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{NULL, NULL}
	};

	i = 0;
	while (instructions[i].opcode != NULL)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
		i = i + 1;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
