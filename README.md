# Monty ByteCode Interpreter
Monty 0.98 is a scripting language that is first compiled into Monty byte codes, similar to Python. This project involves creating an interpreter for Monty ByteCodes files in the C programming language.

## Compilation & Output
Compile the code with: 
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
Any output must be printed on stdout, and any error message must be printed on stderr.

## Monty Program Usage
$ ./monty file
* If no file or more than one argument is given, print USAGE: monty file and exit with EXIT_FAILURE.
* If it's not possible to open the file, print Error: Can't open file <file> and exit with EXIT_FAILURE.
* If the file contains an invalid instruction, print L<line_number>: unknown instruction <opcode> and exit with EXIT_FAILURE.
* If unable to malloc, print Error: malloc failed and exit with EXIT_FAILURE.

## Opcodes
1. push, pall
push
The push opcode pushes an element onto the stack.
Usage: push <int>
* If <int> is not an integer or no argument is given, print L<line_number>: usage: push integer and exit with EXIT_FAILURE.
pall
The pall opcode prints all values on the stack.
Usage: pall
* If the stack is empty, do nothing.
2. pint
pint
The pint opcode prints the value at the top of the stack, followed by a new line.
Usage: pint
* If the stack is empty, print L<line_number>: can't pint, stack empty and exit with EXIT_FAILURE.
3. pop
pop
The pop opcode removes the top element of the stack.
Usage: pop
* If the stack is empty, print L<line_number>: can't pop an empty stack and exit with EXIT_FAILURE.
4. swap
swap
The swap opcode swaps the top two elements of the stack.
Usage: swap
* If the stack contains less than two elements, print L<line_number>: can't swap, stack too short and exit with EXIT_FAILURE.
5. add
add
The add opcode adds the top two elements of the stack.
Usage: add
* If the stack contains less than two elements, print L<line_number>: can't add, stack too short and exit with EXIT_FAILURE.
* The result is stored in the second top element of the stack, and the top element is removed.
6. nop
nop
The nop opcode does nothing.
Usage: nop

## Repository
GitHub Repository: holbertonschool-monty

## AUTHORS
Leandro Pagani & Manuel Morales
