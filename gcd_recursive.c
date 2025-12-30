/*
Part B - Exp 2
Title: Program to find GCD of two numbers using recursion
Register Number: 408CS15015
*/

#include <stdio.h>

/* Recursive function to find GCD */
int gcd(int m, int n)
{
    if (n == 0)
        return m;
    else
        return gcd(n, m % n);
}

int main()
{
    int m, n, res;

    printf("Enter the values of m and n: ");
    scanf("%d %d", &m, &n);

    res = gcd(m, n);

    printf("GCD(%d, %d) = %d\n", m, n, res);

    return 0;
}
