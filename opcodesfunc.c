#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
/**
 * _push - Pushes An Element To The Stack.
 * @Node: Stack
 * @**top: Double pointer to top of stack
 * Return: Void
 */
typedef struct Node {
    int data;
    struct Node *next;
} Node;

void _push(Node **top, int value) 
{
    intvalue = atoi(value)
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = intvalue;
    newNode->next = *top;
    *top = newNode;
}
/**
 * _pall - Prints all the values on the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: The line number.
 */
void _pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack; // Start from the top of the stack

    while (current != NULL)
    {
        printf("%d\n", current->n); // Print the value of the current node
        current = current->next;      // Move to the next node
    }
}
