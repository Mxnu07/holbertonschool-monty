#include "monty.h"

/**
 * add_ - Adds the top two elements of the stack.
 * @stack: Double pointer to the stack (top of the stack).
 * @line_number: Line number where the operation is called.
 */
void add_(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL) // Check if the stack is too short (less than two elements).
    {
        fprintf(stderr, "L%u: Error: can't add, stack too short\n", line_number); // Print an error message and exit if the stack is too short.
        exit(EXIT_FAILURE);
    }

    stack_t *tmp = (*stack)->next;
    tmp->n += (*stack)->n; // Proceed only if there are at least two elements on the stack.

    pop_(stack, line_number); // Remove the top element from the stack.

    
    tmp->prev = NULL; // Updates the prev pointer of tmp to NULL as it becomes the new top of the stack.
    if (*stack != NULL) 
    {
        (*stack)->prev = tmp; // Updates the prev pointer of the new top of stack to point to tmp
    }
    *stack = tmp;
}