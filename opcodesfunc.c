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
