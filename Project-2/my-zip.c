#include <stdio.h>
#include <stdlib.h>

void zipStream(FILE *input) {
    char current, previous;
    int count = 0;

    while (fread(&current, sizeof(char), 1, input)) {
        if (count == 0) {
            previous = current;
            count = 1;
        } else if (current == previous) {
            count++;
        } else {
            fwrite(&count, sizeof(int), 1, stdout);
            fwrite(&previous, sizeof(char), 1, stdout);
            previous = current;
            count = 1;
        }
    }
    if (count > 0) {
        fwrite(&count, sizeof(int), 1, stdout);
        fwrite(&previous, sizeof(char), 1, stdout);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: my-zip <file1> [file2 ...]\n");
        exit(1);
    }

    for (int i = 1; i < argc; i++) {
        FILE *file = fopen(argv[i], "r");
        if (!file) {
            printf("my-zip: cannot open file\n");
            exit(1);
        }
        zipStream(file);
        fclose(file);
    }
    return 0;
}
