#include "monty.h"
/**
 * op_add - function that adds the top two elements of the stack
 * @stack: stack structure
 * number_of_lines: number of lines in the file
 */

void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	stack_t *current = *stack;
	int count = 0;

	while (current)
	{
		count++;
		current = current->next;
	}

	if (count < 2)
	{
		if (tmp == NULL || (*stack)->next == NULL)
		{
			fprint(stderr, "L%d: can't add, stack too short\n",
			       line_number);
			exit(EXIT_FAILURE);
		}
	}
	(tmp->next)-> = tmp-> + (tmp->next)->n;
	op_pop(stack, line_number);
}
