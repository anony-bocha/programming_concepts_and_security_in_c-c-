#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *line = NULL;
    size_t len = 0;

    printf("Enter text: ");
    getline(&line, &len, stdin);

    printf("You entered: %s", line);

    free(line);
    return 0;
}

