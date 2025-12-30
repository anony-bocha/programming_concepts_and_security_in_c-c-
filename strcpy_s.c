#include <stdio.h>
#include <string.h>

int main(void) {
    char dest[10];

    if (strcpy_s(dest, sizeof(dest), "Hello") == 0) {
        printf("%s\n", dest);
    }
    return 0;
}

