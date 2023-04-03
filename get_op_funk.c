#include "monty.h"

/**
 * get_opcode - compares instructions to opcodes and calls functions
 * Return: 0 on success, EXIT_FAILURE on error
 */

int get_opcode(void)
{
	instruction_t opfunk[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"add", op_add},
		{"pop", op_pop},
		{"pint", op_pint},
		{"swap", op_swap},
		{"nop", op_nop},
		{NULL, NULL}};

	int i = 0;

	for (; opfunk[i].opcode != NULL; i++)
	{
		if (strcmp(opfunk[i].opcode, handle.rev_token) == 0)
		{
			opfunk[i].f(&handle.head, handle.number_lines);
			break;
		}
	}

	if (!opfunk[i].opcode)
	{
		fprintf(stderr, "L%ld: unknown instruction %s\n",
		handle.number_lines, handle.rev_token);
		free_structure();
		exit(EXIT_FAILURE);
	}

	return (0);
}
