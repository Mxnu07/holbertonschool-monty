#include "monty.h"

/**
 * swap_ - Swaps the top two elements of the stack.
 * @stack: Double pointer to the stack (top of the stack).
 * @line_number: Line number where the operation is called.
 */
void swap_(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL) // Check if the stack is too short (less than two elements)
    {
        fprintf(stderr, "L%u: Error: can't swap, stack too short\n", line_number); // If it's too short, print an error message
        exit(EXIT_FAILURE);
    }

    stack_t *top = *stack;
    stack_t *second = top->next;

    top->next = second->next; // Update 'top' to point to the element after 'second'
    top->prev = second; // Update 'top' to point to 'second' as its previous element
    second->next = top; // Update 'second' to point to 'top' as its next element
    second->prev = NULL; // Since 'second' is now at the top, its previous element is NULL

    top->next->prev = top; // Update the previous pointer of the element after 'top' to point to 'top'

    *stack = second; // Update the double pointer 'stack' to point to 'second', as 'second' is now at the top of the stack
}