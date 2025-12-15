#include <stdio.h>
#include <conio.h>

int main()
{
    FILE *fp;
    char c;

    fp = fopen("D:\\c\\n.txt", "w");  

    if (fp == NULL)
    {
        printf("File cannot be opened. Check if it is open elsewhere.\n");
        return 1;
    }

    printf("Enter text (Ctrl+Z then Enter to stop):\n");

    while ((c = getchar()) != EOF)
    {
        putc(c, fp);
    }

    fclose(fp);
    printf("File saved successfully!\n");

    getch();
    return 0;
}

