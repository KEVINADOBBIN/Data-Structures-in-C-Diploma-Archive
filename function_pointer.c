#include <stdio.h>

/* Function definition */
int sum(int x, int y)
{
    return x + y;
}

int main()
{
    int (*fp)(int, int);  // function pointer declaration
    int s;

    fp = sum;             // assigning function address
    s = fp(10, 15);       // calling function using pointer

    printf("Sum is %d\n", s);

    return 0;
}
