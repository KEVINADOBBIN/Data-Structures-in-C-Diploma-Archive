#include <stdio.h>

/* Function declarations */
void call_val(int x, int y);
void call_ref(int *p, int *q);

int main()
{
    int num1, num2;

    printf("Enter two numbers:\n");
    scanf("%d %d", &num1, &num2);

    printf("\nBefore calling any function\n");
    printf("num1 = %d, num2 = %d\n", num1, num2);

    printf("\nAfter calling call by value function\n");
    call_val(num1, num2);
    printf("num1 = %d, num2 = %d\n", num1, num2);

    printf("\nAfter calling call by reference function\n");
    call_ref(&num1, &num2);
    printf("num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}

/* Call by Value */
void call_val(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

/* Call by Reference */
void call_ref(int *p, int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}
