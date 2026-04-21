#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }

    int count = 0;
    int prev = -1;
    int ch;

    for (int i = 1; i < argc; i++) {
        FILE *file = fopen(argv[i], "r");
        if (!file) {
            printf("wzip: cannot open file\n");
            exit(1);
        }

        while ((ch = fgetc(file)) != EOF) {
            if (ch == prev) {
                count++;
            } else {
                if (prev != -1) {
                    fwrite(&count, sizeof(int), 1, stdout);
                    fwrite(&prev, sizeof(char), 1, stdout);
                }
                prev = ch;
                count = 1;
            }
        }

        fclose(file);
    }

    if (prev != -1) {
        fwrite(&count, sizeof(int), 1, stdout);
        fwrite(&prev, sizeof(char), 1, stdout);
    }

    return 0;
}