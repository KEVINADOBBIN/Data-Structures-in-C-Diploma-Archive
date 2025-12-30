#include <stdio.h>

int main()
{
    FILE *fp;
    char c;
    int count = 0;

    printf("Enter the data (Press Ctrl+D on Linux/macOS or Ctrl+Z then Enter on Windows to stop):\n");

    fp = fopen("input.txt", "w");
    if (fp == NULL)
    {
        printf("File cannot be created\n");
        return 0;
    }

    /* Writing data to file */
    while ((c = getchar()) != EOF)
    {
        putc(c, fp);
    }
    fclose(fp);

    /* Reading data from file */
    fp = fopen("input.txt", "r");
    if (fp == NULL)
    {
        printf("File cannot be opened\n");
        return 0;
    }

    while ((c = getc(fp)) != EOF)
    {
        count++;
    }

    printf("\nThe total number of characters = %d\n", count);

    fclose(fp);

    return 0;
}
