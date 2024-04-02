#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 256

int main(int argc, char *argv[])
{
  // check if args are valid
  switch (argc)
  {
    case 1:
      fprintf(stderr, "No filename provided\n");
      return 1;
    case 2:
      break;
    case 3:
      if (strcmp(argv[1], argv[2]) == 0)
      {
        fprintf(stderr, "Input and output file must differ\n");
        return 1;
      }
      break;
    default:
      fprintf(stderr, "Usage: reverse <input> <output>\n");
      return 1;
  }

  // open the file for reading
  FILE *fileRead = fopen(argv[1], "r");
  if (fileRead == NULL)
  {
    fprintf(stderr, "error: cannot open file '%s'\n", argv[1]);
    return 1;
  }

  // malloc for storing all lines
  char **lines = malloc(INITIAL_SIZE * sizeof(char *));
  int lineCount = 0;
  int lineSize = INITIAL_SIZE;
  if (lines == NULL)
  {
    fprintf(stderr, "malloc failed\n");
    return 1;
  }

  // malloc for storing each line
  char *line = malloc(INITIAL_SIZE);
  int charCount = 0;
  int bufferSize = INITIAL_SIZE;
  if (line == NULL)
  {
    fprintf(stderr, "malloc failed\n");
    return 1;
  }

  // read file char at a time
  int c;
  while ((c = fgetc(fileRead)) != EOF)
  {
    // check if line buffer is full, reallocate if necessary
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

    // check EOF or line
    if (c == '\n' || c == EOF)
    {
      line[charCount] = '\0';

      // check if lines array is full, reallocate if necessary
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

      // store line in array
      lines[lineCount] = line;
      lineCount++;

      // reset line buffer
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
      // add char to buffer
      line[charCount] = c;
      charCount++;
    }
  }

  fclose(fileRead);

  // check if output filename is provided
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

  // print lines in reverse order
  for (int i = lineCount - 1; i >= 0; i--)
  {
    if (fileWrite != NULL)
    {
      // write to the output file
      fprintf(fileWrite, "%s\n", lines[i]);
    }
    else
    {
      // write to stdout
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
