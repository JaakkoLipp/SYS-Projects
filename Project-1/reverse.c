#include <stdio.h>

int main(int argc, char *argv[])
{
  // read lines of input file
  FILE *fileRead = fopen(argv[1], "r");
  if (fileRead == NULL)
  {
    printf("File not found");
    return 1;
  }
   char line[256];
   while (fgets(line, sizeof(line), fileRead))
   {
     printf("%s", line);
   }
   fclose(fileRead);
   return 0;
}