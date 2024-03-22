# my-grep.c

## Overview

The `my-grep` program is a simplified version of the Unix `grep` utility. It searches for lines containing a specified search term in one or more files and prints those lines to the standard output. If no file is provided, `my-grep` reads from standard input (stdin), allowing it to be used in a pipeline of commands.

## Usage

```plaintext
my-grep searchterm [file ...]
```

- `searchterm`: The string to search for within each file or stdin.
- `[file ...]`: Optional. One or more files to search. If no files are provided, `my-grep` searches stdin.

## Compilation

To compile the `my-grep` program, use the following command:

```bash
gcc -o my-grep my-grep.c
```

## Functionality

The program consists of two main parts: the `grep` function and the `main` function.

### grep Function

```c
void grep(FILE *f, char *searchterm);
```

- **Purpose**: Searches a single file (or stdin) for lines containing the specified search term and prints those lines.
- **Parameters**:
  - `FILE *f`: A file pointer to the file being searched. Can also be stdin.
  - `char *searchterm`: The string to search for in the file's content.
- **Implementation Details**:
  - Reads the file line by line.
  - Uses `strstr` to search for the `searchterm` in each line.
  - If `searchterm` is found, the line is printed to stdout.

### Main Function

The `main` function processes command-line arguments, handles file opening and closing, and calls the `grep` function accordingly.

- **Command-Line Arguments**:
  - The first argument after the program name is considered the `searchterm`.
  - Any subsequent arguments are treated as filenames to be searched.
- **Behavior**:
  - If no arguments are provided, it prints usage information and exits.
  - If only `searchterm` is provided (i.e., `argc == 2`), it reads from stdin.
  - If one or more filenames are provided, it opens and searches each file for the `searchterm`.
- **Error Handling**:
  - If a file cannot be opened, it prints an error message and exits.

## Examples

Search for the term "error" in a file named "log.txt":

```bash
./my-grep error log.txt
```

Search for the term "foo" across multiple files:

```bash
./my-grep foo file1.txt file2.txt
```

Use in a pipeline to search for "hello" in the output of another command:

```bash
echo -e "hello\nworld" | ./my-grep hello
```

## Error Messages

- If the program is invoked without a search term, it will display: `my-grep: searchterm [file ...]` and exit.
- If a specified file cannot be opened, it will display: `my-grep: cannot open file` and exit.

## Exit Codes

- `0`: Program executed successfully.
- `1`: Program encountered an error, such as missing arguments or unable to open a file.
