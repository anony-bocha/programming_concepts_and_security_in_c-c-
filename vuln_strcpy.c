#include <stdio.h>
#include <string.h>

int main() {
    char src[100];
    char dest[8];

    printf("Enter input: ");
    fgets(src, sizeof(src), stdin);

    src[strcspn(src, "\n")] = '\0';

    strcpy(dest, src);   

    printf("Copied: %s\n", dest);
    return 0;
}

