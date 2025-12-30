/*
Register Number: 408CS15015
Experiment 8
Title: Program to search a given number using Linear Search
*/

#include <stdio.h>

/* Function for linear search */
int linear(int key, int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
            return i + 1; // returning position (1-based)
    }
    return 0; // not found
}

int main()
{
    int a[20], n, i, key, pos;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter the key to be searched: ");
    scanf("%d", &key);

    pos = linear(key, a, n);

    if (pos == 0)
        printf("Search unsuccessful. %d not found.\n", key);
    else
        printf("Key %d found at position %d.\n", key, pos);

    return 0;
}
