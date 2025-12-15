#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned int n;
    size_t size;
    unsigned int i;
    int *arr;

    printf("Enter number of integers to allocate: ");
    scanf("%u", &n);

    size = n * sizeof(int);

    printf("Requested size = %u * %lu = %lu bytes\n", n, sizeof(int), size);

    arr = (int *)malloc(size);
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Memory allocated. Writing %u integers...\n", n);

    for (i = 0; i < n; i++) {
        arr[i] = i;
    }

    printf("Done. (Heap overflow may have occurred)\n");

    free(arr);
    return 0;
}

