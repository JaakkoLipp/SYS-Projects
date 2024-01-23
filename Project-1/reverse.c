#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 256

int main(int argc, char *argv[])
{
  // Check if filename is provided
  if (argc < 2)
  {
    fprintf(stderr, "No filename provided\n");
    return 1;
  }

  // Check if too many arguments are passed
  if (argc > 3)
  {
    fprintf(stderr, "Usage: reverse <input> <output>\n");
    return 1;
  }

  // Check if input and output file are the same
  if (argc == 3 && strcmp(argv[1], argv[2]) == 0)
  {
    fprintf(stderr, "Input and output file must differ\n");
    return 1;
  }

  // Open the file for reading
  FILE *fileRead = fopen(argv[1], "r");
  if (fileRead == NULL)
  {
    fprintf(stderr, "error: cannot open file '%s'\n", argv[1]);
    return 1;
  }

  // Allocate memory for storing lines
  char **lines = malloc(INITIAL_SIZE * sizeof(char *));
  int lineCount = 0;
  int lineSize = INITIAL_SIZE;
  if (lines == NULL)
  {
    fprintf(stderr, "malloc failed\n");
    return 1;
  }

  // Allocate memory for storing a line
  char *line = malloc(INITIAL_SIZE);
  int charCount = 0;
  int bufferSize = INITIAL_SIZE;
  if (line == NULL)
  {
    fprintf(stderr, "malloc failed\n");
    return 1;
  }

  // Read the file character by character
  int c;
  while ((c = fgetc(fileRead)) != EOF)
  {
    // Check if line buffer is full, reallocate if necessary
    if (charCount == bufferSize - 1)
    {
      bufferSize *= 2;
      line = realloc(line, bufferSize);
      if (line == NULL)
      {
        fprintf(stderr, "malloc failed\n");
        return 1;
      }
    }

    // Check if end of line OR file is reached
    if (c == '\n' || c == EOF)
    {
      line[charCount] = '\0';

      // Check if lines array is full, reallocate if necessary
      if (lineCount == lineSize - 1)
      {
        lineSize *= 2;
        lines = realloc(lines, lineSize * sizeof(char *));
        if (lines == NULL)
        {
          fprintf(stderr, "malloc failed\n");
          return 1;
        }
      }

      // Store the line in the lines array
      lines[lineCount] = line;
      lineCount++;

      // Reset line buffer
      bufferSize = INITIAL_SIZE;
      line = malloc(bufferSize);
      if (line == NULL)
      {
        fprintf(stderr, "malloc failed\n");
        return 1;
      }
      charCount = 0;
    }
    else
    {
      // Add character to the line buffer
      line[charCount] = c;
      charCount++;
    }
  }

  fclose(fileRead);

  // Check if output filename is provided
  FILE *fileWrite = NULL;
  if (argc == 3)
  {
    fileWrite = fopen(argv[2], "w");
    if (fileWrite == NULL)
    {
      fprintf(stderr, "error: cannot open file '%s'\n", argv[2]);
      return 1;
    }
  }

  // Print lines in reverse order
  for (int i = lineCount - 1; i >= 0; i--)
  {
    if (fileWrite != NULL)
    {
      // Write to the output file
      fprintf(fileWrite, "%s\n", lines[i]);
    }
    else
    {
      // Write to stdout
      printf("%s\n", lines[i]);
    }
    free(lines[i]);
  }

  free(lines);

  // Close the output file
  if (fileWrite != NULL)
  {
    fclose(fileWrite);
  }

  return 0;
}
