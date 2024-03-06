#include <stdio.h>
#include <stdlib.h>

void compressFile(FILE* inputFile) {
  char currentChar, previousChar;
  int count = 1;

  if (fread(&previousChar, sizeof(char), 1, inputFile) != 1) {
    return;
  }

  while (fread(&currentChar, sizeof(char), 1, inputFile) == 1) {
    if (currentChar == previousChar) {
      count++;
    } else {
      fwrite(&count, sizeof(int), 1, stdout);
      fwrite(&previousChar, sizeof(char), 1, stdout);
      count = 1;
      previousChar = currentChar;
    }
  }

  fwrite(&count, sizeof(int), 1, stdout);
  fwrite(&previousChar, sizeof(char), 1, stdout);
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("my-zip: file1 [file2 ...]\n");
    return 1;
  }

  for (int i = 1; i < argc; i++) {
    FILE* inputFile = fopen(argv[i], "rb");
    if (inputFile == NULL) {
      printf("Error opening input file: %s\n", argv[i]);
      return 1;
    }

    compressFile(inputFile);

    fclose(inputFile);
  }

  return 0;
}
