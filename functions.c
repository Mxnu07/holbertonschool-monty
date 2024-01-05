#include "monty.h"

/**
 * validate_arguments - checks the number of command-line
 * arguments
 * @argc: number of command-line
*/

void validate_arguments(int argc)
{
    if (argc == 2)
    return;
    dprintf(2, "USAGE: monty file\n");
    exit(EXIT_FAILURE);
}

/**
 * initialize_arguments - initializes a pointer to
 * arg_s structure.
*/
void initialize_arguments()
{
    arguments = malloc(sizeof(arg_t));
    if (arguments == NULL)
    malloc_failed();

    arguments->instruction = malloc(sizeof(instruction_t));
    if (arguments->instruction == NULL)
    malloc_failed();
    
    arguments->n_tokens = 0;
    arguments->line_number = 0;
    arguments->stream = NULL;
    arguments->line = NULL;
}

/**
 * malloc_failed - handles the error when malloc fails to
 * allocate memory
*/

void malloc_failed(void)
{
    dprintf(2, "Error: malloc failed\n");
    free_arguments();
    exit(EXIT_FAILURE);
}

/**
 * getting_stream_failed - handles the error when reading
 * a file fails.
 * @fileName: the name of the file taht failed to open
*/

void getting_stream_failed(char *fileName)
{
    int fd;

    fd = oen(fileName, O_RDONLY);
    if (fd == -1)
    getting_stream_failed(fileName);

    arguments->stream = fdopen(fd, "r");
    if (arguments->stream == NULL)
    {
        close(fd);
        getting_stream_failed
    }
}