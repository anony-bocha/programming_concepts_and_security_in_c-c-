#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *sourceFile = "D:/c/filee.txt";
    const char *destFile = "D:/c/empty.txt";

    FILE *src;
    FILE *dest;
    int ch;

    src = fopen(sourceFile, "r");
    if (src == NULL) {
        perror("Error opening source file");
        return EXIT_FAILURE;
    }

    dest = fopen(destFile, "w");
    if (dest == NULL) {
        perror("Error opening destination file");
        fclose(src);
        return EXIT_FAILURE;
    }

    while ((ch = fgetc(src)) != EOF) {
        if (fputc(ch, dest) == EOF) {
            perror("Error writing to destination file");
            fclose(src);
            fclose(dest);
            return EXIT_FAILURE;
        }
    }

    printf("File copied successfully from '%s' to '%s'.\n", sourceFile, destFile);

    fclose(src);
    fclose(dest);

    dest = fopen(destFile, "r");
    if (dest == NULL) {
        perror("Error reopening destination file");
        return EXIT_FAILURE;
    }

    printf("\nContents of '%s':\n", destFile);
    while ((ch = fgetc(dest)) != EOF) {
        putchar(ch);
    }

    fclose(dest);
    return EXIT_SUCCESS;
}

