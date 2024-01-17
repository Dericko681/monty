#ifndef MONTY_H
#define MONTY_H

#include <ctype.h>

/* Data structure for a doubly linked list node */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/* Data structure for an opcode and its function */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Global variable */
extern char *monty_token;

/* Function prototypes */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

/* Add other function prototypes as needed */

#endif /* MONTY_H */
