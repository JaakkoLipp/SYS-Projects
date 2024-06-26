#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  // No files specified
  if (argc == 1) {
    return 0;
  }

  // Loop files
  for (int i = 1; i < argc; i++) {
    // Reading
    FILE *fp = fopen(argv[i], "r");
    if (fp == NULL) {
      printf("my-cat: cannot open file\n");
      return 1;
    }

    // Print contents
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
      printf("%s", buffer);
    }
    // Close file
    fclose(fp);
  }
  return 0;
}
