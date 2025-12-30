/*
Register Number: 408CS15015
Part B - Exp 11
Title: Evaluate a postfix expression using stack operations
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAXCOLS 80

struct stack
{
    int top;
    double items[MAXCOLS];
};

/* Function prototypes */
int empty(struct stack *ps);
void push(struct stack *ps, double x);
double pop(struct stack *ps);
double eval(char expr[]);
int isdigit_custom(char c);
double oper(char symb, double op1, double op2);

int main()
{
    char expr[MAXCOLS];
    int pos = 0;

    printf("Enter the postfix expression (single-digit operands only):\n");
    while ((expr[pos++] = getchar()) != '\n');
    expr[--pos] = '\0';

    printf("The original expression is: %s\n", expr);
    printf("The evaluated value is: %f\n", eval(expr));

    return 0;
}

/* Evaluate postfix expression */
double eval(char expr[])
{
    struct stack opndstk;
    opndstk.top = -1;
    double op1, op2, value;
    int pos, c;

    for (pos = 0; (c = expr[pos]) != '\0'; pos++)
    {
        if (isdigit_custom(c))
        {
            push(&opndstk, (double)(c - '0'));
        }
        else
        {
            op2 = pop(&opndstk);
            op1 = pop(&opndstk);
            value = oper(c, op1, op2);
            push(&opndstk, value);
        }
    }

    return pop(&opndstk);
}

/* Custom isdigit function to avoid conflict with stdlib */
int isdigit_custom(char symb)
{
    return (symb >= '0' && symb <= '9');
}

/* Perform operation */
double oper(char symb, double op1, double op2)
{
    switch (symb)
    {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2;
        case '^': return pow(op1, op2);
        default:
            printf("Illegal operator: %c\n", symb);
            exit(1);
    }
}

/* Push value onto stack */
void push(struct stack *ps, double x)
{
    if (ps->top == MAXCOLS - 1)
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    ps->items[++ps->top] = x;
}

/* Pop value from stack */
double pop(struct stack *ps)
{
    if (empty(ps))
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return ps->items[ps->top--];
}

/* Check if stack is empty */
int empty(struct stack *ps)
{
    return (ps->top == -1);
}
