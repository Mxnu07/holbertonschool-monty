#include "monty.h"
/**
 * pop_ - Removes the top element of the stack.
 * @stack: Double pointer to the stack (top of the stack).
 * @line_number: Line number where the operation is called.
 */
void pop_(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;

    if (*stack == NULL || stack == NULL) // Checks if the stack is empty.
    {
        fprintf(stderr, "L%d: Error: can't pop an empty stack\n", line_number); // If the stack is empty, prints an error message
        exit(EXIT_FAILURE);
    }

    tmp = *stack; // Assigns the top of the stack to a temporary pointer.
    *stack = tmp->next; // Moves the stack pointer to the next element.
    free(tmp); // Frees the memory of the removed element.
}
