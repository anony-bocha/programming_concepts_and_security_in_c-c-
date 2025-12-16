#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *file;

    if (argc < 4)
    {
        printf("Usage: <name> <address> <age>\n");
        return 1;
    }

    
    printf("Name    : %s\n", argv[1]);
    printf("Address : %s\n", argv[2]);
    printf("Age     : %s\n", argv[3]);

    
    file = fopen("data.txt", "w");

    if (file == NULL)
    {
        printf("File creation failed\n");
        return 1;
    }

    
    fprintf(file, "Name: %s\n", argv[1]);
    fprintf(file, "Address: %s\n", argv[2]);
    fprintf(file, "Age: %s\n", argv[3]);

    fclose(file);

    printf("\nData saved successfully to data.txt\n");

    return 0;
}

