/*
Register Number: 408CS15015
Experiment 9
Title: Program to search a given number using Binary Search
*/

#include <stdio.h>

/* Recursive binary search function */
int b_search(int low, int high, int list[], int key)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (key < list[mid])
            return b_search(low, mid - 1, list, key);
        else if (key > list[mid])
            return b_search(mid + 1, high, list, key);
        else
            return mid; // key found
    }
    else
        return -1; // key not found
}

int main()
{
    int list[15], n, i, key, pos;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements in sorted order:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &list[i]);

    printf("Enter the element to be searched: ");
    scanf("%d", &key);

    pos = b_search(0, n - 1, list, key);

    if (pos == -1)
        printf("Search unsuccessful. %d not found.\n", key);
    else
        printf("Search successful! Element %d found at position %d.\n", key, pos + 1);

    return 0;
}
