#include "monty.h"

/**
 * free_stack - Frees the entire stack.
 * @stack: Pointer to the top of the stack.
 */
void free_stack(stack_t **stack)
{
    // Implementation as previously provided
}

// Other stack-related functions (push, pop, pall, etc.) can go here

#include "monty.h"

/**
 * pop - Removes the top element of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number of the opcode in the Monty byte code file.
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    *stack = temp->next;

    if (*stack != NULL)
        (*stack)->prev = NULL;

    free(temp);
}

// Other stack-related functions (push, pall, free_stack, etc.) can go here

