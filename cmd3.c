#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        printf("Please provide at least 3 arguments: <name> <address> <age>\n");
        return 1;
    }
	
    printf("|-----------------------------------|\n");
    printf("    Program name:>%s\n", argv[0]);
	printf("|-----------------------------------|\n");
    printf("    Name:>%s\n", argv[1]);
	printf("|-----------------------------------|\n");
    printf("    Address:>%s\n", argv[2]);
	printf("|-----------------------------------|\n");
    printf("    Age:> %s\n", argv[3]);
    printf("|-----------------------------------|\n");
    return 0;
}

