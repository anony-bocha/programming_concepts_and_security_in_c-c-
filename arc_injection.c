#include <stdio.h>
#include <string.h>

int isPasswordOK(void)
{
    char password[12];

    gets(password);  

    if (strcmp(password, "goodpass") == 0)
        return 1;

    return 0;
}

int main(void)
{
    int PWStatus;

    puts("Enter password:");
    PWStatus = isPasswordOK();

    if (PWStatus == 0) {
        puts("Access denied");
        return 0;
    }

    puts("Access granted");
    return 0;
}

