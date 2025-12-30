/*
Part B - Exp 3
Title: Program to implement queue using array
Register Number: 408CS15015
*/

#include <stdio.h>
#include <stdlib.h>

#define Q_SIZE 3

int queue[Q_SIZE];
int front = 0, rear = -1;

/* Function to insert element at rear */
void insert_rear(int item)
{
    if (rear == Q_SIZE - 1)
    {
        printf("Queue Overflow!\n");
        return;
    }
    rear++;
    queue[rear] = item;
    printf("Inserted %d into the queue.\n", item);
}

/* Function to delete element from front */
void delete_front()
{
    if (front > rear)
    {
        printf("Queue Underflow!\n");
        front = 0;
        rear = -1;
        return;
    }
    printf("Deleted item is %d\n", queue[front]);
    front++;
    if (front > rear) // Reset queue when empty
    {
        front = 0;
        rear = -1;
    }
}

/* Function to display queue */
void display()
{
    int i;
    if (front > rear)
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements are:\n");
    for (i = front; i <= rear; i++)
    {
        printf("%d\n", queue[i]);
    }
}

int main()
{
    int choice, item;

    while (1)
    {
        printf("\nQueue Operations Menu:\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            insert_rear(item);
            break;

        case 2:
            delete_front();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice! Please enter 1-4.\n");
        }
    }

    return 0;
}
