#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isPasswordOK(void)
{
    char password[12];

    gets(password);   /* ? VULNERABILITY IS HERE */

    return strcmp(password, "goodpass") == 0;
}

int main(void)
{
    int PWStatus;

    puts("Enter password:");
    PWStatus = isPasswordOK();

    if (PWStatus == 0) {
        puts("Access denied");
        exit(-1);
    }

    puts("Access granted");
    return 0;
}

