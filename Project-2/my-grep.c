#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// used on line 38, search one file
void grep(FILE *f, char *searchterm) {
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  while ((read = getline(&line, &len, f)) != -1) {
    // use stringsearch to find the searchterm in the line
    if (strstr(line, searchterm) != NULL) {
      printf("%s", line);
    }
  }

  free(line);
}


int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("my-grep: searchterm [file ...]\n");
    exit(1);
  }

  // standard input
  if (argc == 2) {
    grep(stdin, argv[1]);
  
  // loop through each file
  } else {
    for (int i = 2; i < argc; i++) {
      FILE *f = fopen(argv[i], "r");
      if (f == NULL) {
        printf("my-grep: cannot open file\n");
        exit(1);
      }

      // Call search function
      grep(f, argv[1]);
      fclose(f);
    }
  }

  return 0;
}