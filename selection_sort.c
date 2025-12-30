/*
Register Number: 408CS15015
Experiment 7
Title: Program to sort an array using Selection Sort
*/

#include <stdio.h>

int main()
{
    int a[10], n, i, j, pos, temp, small;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements to sort:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // Selection Sort
    for (i = 0; i < n - 1; i++)
    {
        small = a[i];
        pos = i;

        for (j = i + 1; j < n; j++)
        {
            if (a[j] < small)
            {
                small = a[j];
                pos = j;
            }
        }

        // Swap a[i] and a[pos]
        if (pos != i)
        {
            temp = a[i];
            a[i] = a[pos];
            a[pos] = temp;
        }
    }

    printf("The sorted elements are:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }

    return 0;
}
