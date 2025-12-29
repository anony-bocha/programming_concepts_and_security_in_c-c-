#include <stdio.h>
#include <string.h>

void access_granted() {
    puts("Access granted");
}

void access_denied() {
    puts("Access denied");
}

int main() {
    char input[32];
    void (*auth_result)() = access_denied; 

    printf("Enter password: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    
    if (strncmp(input, "admin", 5) == 0) {
        auth_result = access_granted;
    }

    auth_result();  
    return 0;
}

