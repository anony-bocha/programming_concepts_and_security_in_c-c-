#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char *name;
    name = strdup("CyberSecurity");

    if (name == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("%s\n", name);
    free(name);
    return 0;
}

