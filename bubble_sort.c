/*
Register Number: 408CS15015
Experiment 6
Title: Program to sort an array using Bubble Sort
*/

#include <stdio.h>

int main()
{
    int a[20], n, i, j, temp;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements to sort:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // Bubble Sort
    for (j = 0; j < n - 1; j++)
    {
        for (i = 0; i < n - j - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }

    printf("The sorted elements are:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");

    return 0;
}
