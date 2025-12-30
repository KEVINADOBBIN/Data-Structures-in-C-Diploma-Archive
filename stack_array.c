/*
Part B - Exp 1
Title: Program to illustrate stack operations using arrays
Register Number: 408CS15015
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 3

int main()
{
    int stack[MAX];
    int top = -1;
    int choice, item, i, rpt = 1;

    while (rpt)
    {
        printf("\nStack Operations Menu:\n");
        printf("1. Push (Insert)\n");
        printf("2. Pop (Delete)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // Push
            if (top == MAX - 1)
            {
                printf("Stack Overflow!\n");
            }
            else
            {
                printf("Enter the element to push: ");
                scanf("%d", &item);
                top++;
                stack[top] = item;
            }
            break;

        case 2: // Pop
            if (top == -1)
            {
                printf("Stack Underflow!\n");
            }
            else
            {
                printf("The deleted item is %d\n", stack[top]);
                top--;
            }
            break;

        case 3: // Display
            if (top == -1)
            {
                printf("Stack is empty!\n");
            }
            else
            {
                printf("Elements in the stack are:\n");
                for (i = top; i >= 0; i--)
                {
                    printf("%d\n", stack[i]);
                }
            }
            break;

        case 4: // Exit
            exit(0);

        default:
            printf("Invalid choice! Please enter 1-4.\n");
        }

        printf("Do you want to continue? (1 for Yes / 0 for No): ");
        scanf("%d", &rpt);
    }

    return 0;
}
