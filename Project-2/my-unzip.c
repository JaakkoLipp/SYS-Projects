#include <stdio.h>
#include <stdlib.h>


// takes file, prints uncompressed information
void unzipStream(FILE *input) {
  int count;
  char character;

  while (fread(&count, sizeof(int), 1, input) && fread(&character, sizeof(char), 1, input)) {
    for (int i = 0; i < count; i++) {
      printf("%c", character);
      }
  }
}

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Usage: my-unzip <file1> [file2 ...]\n");
    exit(1);
  }

  for (int i = 1; i < argc; i++) {
    FILE *file = fopen(argv[i], "r");
    if (!file) {
      printf("my-unzip: cannot open file\n");
      exit(1);
      }
    unzipStream(file);
    fclose(file);
  }
  return 0;
}
