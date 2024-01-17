#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void push(stack_t **stack, unsigned int line_number)
{
    /* Check if the argument is provided */
    if (!stack || !line_number)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* Allocate memory for a new stack node */
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    /* Check if the argument is an integer */
    if (!isdigit(*monty_token))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        free(new_node);
        exit(EXIT_FAILURE);
    }

    /* Convert the argument to an integer and assign it to the new node */
    new_node->n = atoi(monty_token);
    new_node->prev = NULL;

    /* Update the stack pointers */
    if (*stack)
    {
        new_node->next = *stack;
        (*stack)->prev = new_node;
    }
    else
    {
        new_node->next = NULL;
    }

    *stack = new_node;
}

/**
 * pall - Prints all the values on the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
    (void)line_number; /* Unused parameter */

    /* Check if the stack is empty */
    if (!stack || !(*stack))
        return;

    /* Print all the values on the stack */
    stack_t *current = *stack;
    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

