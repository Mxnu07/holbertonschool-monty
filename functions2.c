#include "monty.h"

/**
 * tokenize - Tokenizes the input line.
 */

void tokenize(void)
{
	int i = 0;
	char *delims = " \n", *token = NULL, *linecpy = NULL;

	linecpy = malloc(sizeof(char) * (strlen(argument->line) + 1));
	strcpy(linecpy, argument->line);
	argument->n_tokens = 0;
	token = strtok(linecpy, delims);
	while (token)
	{
		argument->n_tokens += 1;
		token = strtok(NULL, delims);
	}

	argument->line_strs = malloc(sizeof(char *) *
			(argument->n_tokens + 1));
	strcpy(linecpy, argument->line);
	token = strtok(linecpy, delims);
	while (token)
	{
		argument->line_strs[i] = malloc(sizeof(char) *
				(strlen(token) + 1));
		if (argument->line_strs[i] == NULL)
			malloc_failed();
		strcpy(argument->line_strs[i], token);
		token = strtok(NULL, delims);
		i++;
	}
	argument->line_strs[i] = NULL;
	free(linecpy);
}

/**
* delete_stack_node - delete node at the head/top
* Return: void
*/

void delete_stack_node(void)
{
	stack_t *tmp;

	tmp = argument->stackHead;
	argument->stackHead = tmp->next;
	free(tmp);
}

/**
* free_stack - free the nodes in a stack list
* @head: first node of a dlistint link
* Return: void
*/
void free_stack(stack_t *head)
{
	if (head == NULL)
		return;

	if (head->next != NULL)
	{
		free_stack(head->next);
	}

	free(head);
}

/**
* is_comment - checks the line_strs if it starts with #"
* Return: 0 or 1
*/
int is_comment(void)
{
	if (
		argument->line_strs &&
		argument->line_strs[0] &&
		argument->line_strs[0][0] == '#'
	)
		return (1);

	return (0);
}
