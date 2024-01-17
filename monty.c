#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "monty.h"

ssize_t getline(char **lineptr, size_t *n, FILE *stream);


/* Global variable for Monty byte code token */
char *monty_token;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    /* Open the Monty byte code file */
    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /* Initialize the stack */
    stack_t *stack = NULL;

    /* Read and execute Monty byte code instructions */
    unsigned int line_number = 0;
    while (getline(&monty_token, NULL, file) != -1)
    {
        line_number++;

        /* Execute task based on opcode */
        if (strcmp(monty_token, "push") == 0)
        {
            push(&stack, line_number);
        }
        else if (strcmp(monty_token, "pall") == 0)
        {
            pall(&stack, line_number);
        }
        /* Add more task-specific conditions as needed */

        /* Reset monty_token for the next iteration */
        monty_token = strtok(NULL, " \n\t\r");
    }

    /* Close the file and free memory */
    fclose(file);
    free(monty_token);
    free_stack(&stack);  /* Assuming you have a function to free the stack */

    return 0;
}

