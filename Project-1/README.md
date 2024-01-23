# Documentation for reverse.c

## Overview

`reverse.c` reads lines from an input file, stores them in a dynamic array, and then writes them to an output file in reverse order. If no output file is provided, it prints the lines to the standard output.

## Usage

Run the program in a linux terminal with the following syntax:

```
reverse <input> <output>
```

Where:

- `<input>` is the name of the input file.
- `<output>` is the name of the output file (optional).

## Error Handling

The program includes the following error handling:

- If the input file and output file are the same, it prints an error message "Input and output file must differ" and exits with return code 1.
- If the user specifies an input file or output file that cannot be opened, it prints an error message "error: cannot open file 'filename'" and exits with return code 1.
- If `malloc()` fails to allocate memory, it prints the error message "malloc failed" and exits with return code 1.
- If the user runs the program with too many arguments, it prints "usage: reverse <input> <output>" and exits with return code 1.

All error messages are printed to `stderr` rather than `stdout`.

## Code Structure

The program begins by checking the command-line arguments and opening the input file. It then reads lines from the input file into a dynamic array, resizing the array as needed.

If an output file is specified, it opens the output file for writing. It then writes the lines from the array to the output file in reverse order, or to `stdout` if no output file is specified.

Finally, it frees the memory allocated for the array and closes the output file if it is open.

## Memory Management

The program uses dynamic memory allocation to store the lines from the input file. It starts with an array of a certain size and doubles the size of the array whenever it becomes full. It also uses dynamic memory allocation to store each line of text, resizing the buffer as needed to accommodate long lines.

When the program has finished writing the lines to the output file, it frees the memory allocated for each line and for the array itself. This ensures that the program does not leak memory, even if the input file is very large.
