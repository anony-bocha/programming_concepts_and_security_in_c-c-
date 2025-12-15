#include <stdio.h>
#include "functions.c"

int main() {
    int x, y;      
    int result;    
    printf("Enter first number: ");
    scanf("%d", &x);

    printf("Enter second number: ");
    scanf("%d", &y);

    result = safe_add(x, y);

    printf("Sum = %d\n", result);

    return 0;
}

