/*
Experiment 8
Title: Program to display the contents of the file created in Experiment 7
Register Number: 408CS15015
*/

#include <stdio.h>
#include <stdlib.h>

struct book
{
    int bookno;
    char name[20];
    char author[20];
    char publisher[20];
    int price;
};

int main()
{
    FILE *fptr;
    char filename[50];
    struct book a[5];
    int i;

    printf("Enter the filename to read: ");
    scanf("%s", filename);

    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("Error: Cannot open file %s\n", filename);
        return 0;
    }

    printf("\nBookNo\tName\tAuthor\tPublisher\tPrice\n");
    printf("---------------------------------------------------\n");

    for (i = 0; i < 5; i++)
    {
        fscanf(fptr, "%d %s %s %s %d", 
               &a[i].bookno, 
               a[i].name, 
               a[i].author, 
               a[i].publisher, 
               &a[i].price);

        printf("%d\t%s\t%s\t%s\t%d\n",
               a[i].bookno, 
               a[i].name, 
               a[i].author, 
               a[i].publisher, 
               a[i].price);
    }

    fclose(fptr);

    return 0;
}
