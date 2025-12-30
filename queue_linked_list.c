/*
Part B - Exp 5
Title: Program to implement queue using linked list
Register Number: 408CS15015
*/

#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct node
{
    int info;
    struct node* link;
};

typedef struct node* NODE;

/* Function to allocate memory for a new node */
NODE getnode()
{
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if (x == NULL)
    {
        printf("Out of memory!\n");
        exit(0);
    }
    return x;
}

/* Function to free a node */
void freenode(NODE x)
{
    free(x);
}

/* Insert item at the rear of the queue */
NODE insert_rear(int item, NODE first)
{
    NODE temp = getnode();
    temp->info = item;
    temp->link = NULL;

    if (first == NULL)
        return temp;

    NODE cur = first;
    while (cur->link != NULL)
        cur = cur->link;

    cur->link = temp;
    return first;
}

/* Delete item from the front of the queue */
NODE delete_front(NODE first)
{
    if (first == NULL)
    {
        printf("Queue is empty! Cannot delete.\n");
        return first;
    }

    NODE temp = first;
    printf("Item deleted = %d\n", first->info);
    first = first->link;
    freenode(temp);

    return first;
}

/* Display the queue */
void display(NODE first)
{
    if (first == NULL)
    {
        printf("Queue is empty!\n");
        return;
    }

    NODE temp = first;
    printf("Queue elements are:\n");
    while (temp != NULL)
    {
        printf("%d\n", temp->info);
        temp = temp->link;
    }
    printf("\n");
}

int main()
{
    NODE first = NULL;
    int choice, item;

    while (1)
    {
        printf("\nQueue Operations Menu:\n");
        printf("1. Insert Rear\n2. Delete Front\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the item to insert: ");
            scanf("%d", &item);
            first = insert_rear(item, first);
            break;

        case 2:
            first = delete_front(first);
            break;

        case 3:
            display(first);
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice! Enter 1-4.\n");
        }
    }

    return 0;
}
