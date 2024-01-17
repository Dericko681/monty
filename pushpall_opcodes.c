#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

int stack[STACK_SIZE];
int top = -1;  // Initialize the stack top

// Function to push an element onto the stack
void push(int value) {
    if (top == STACK_SIZE - 1) {
        fprintf(stderr, "Error: Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack[++top] = value;
}

// Function to print all values on the stack
void pall() {
    if (top == -1) {
        // Stack is empty, nothing to print
        return;
    }
    
    int i;
    for (i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    // Example usage
    push(10);
    push(20);
    push(30);

    pall();  // Should print 30, 20, 10

    return 0;
}
