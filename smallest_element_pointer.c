#include <stdio.h>

int main()
{
    int num[10];
    int *p, i, small;

    printf("Enter 10 elements:\n");

    for (i = 0; i < 10; i++)
    {
        scanf("%d", &num[i]);
    }

    p = num;          // pointer points to first element
    small = *p;       // assume first element is smallest

    for (i = 1; i < 10; i++)
    {
        if (*(p + i) < small)
        {
            small = *(p + i);
        }
    }

    printf("Smallest element in the array is %d\n", small);

    return 0;
}
