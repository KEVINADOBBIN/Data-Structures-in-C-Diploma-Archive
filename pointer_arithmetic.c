/*
Experiment 1
Title: Program to illustrate the use of pointers in arithmetic operations
Register Number: 408cs15015
*/

#include <stdio.h>

int main()
{
    int a, b, x, y, z;
    int *p1, *p2;

    a = 12;
    b = 4;

    p1 = &a;
    p2 = &b;

    x = (*p1) * (*p2) - 6;
    y = 4 - (*p2) / (*p1) + 10;

    printf("Address of a = %p\n", (void *)p1);
    printf("Address of b = %p\n", (void *)p2);
    printf("a = %d, b = %d\n", a, b);
    printf("x = %d, y = %d\n", x, y);

    *p2 = *p2 + 3;
    *p1 = *p1 - 5;

    z = (*p1) * (*p2) - b;

    printf("a = %d, b = %d\n", a, b);
    printf("z = %d\n", z);

    return 0;
}
