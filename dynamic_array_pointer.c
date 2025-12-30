#include <stdio.h>
#include <stdlib.h>   // for calloc() and free()

int main()
{
    int *a, i, j, n;

    printf("Enter number of elements:\n");
    scanf("%d", &n);

    a = (int *)calloc(n, sizeof(int));

    if (a == NULL)
    {
        printf("Insufficient memory\n");
        return 0;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    j = 0;
    for (i = 1; i < n; i++)
    {
        if (a[i] > a[j])
        {
            j = i;
        }
    }

    printf("The biggest element = %d is found at position = %d\n", a[j], j + 1);

    free(a);

    return 0;
}
