/*
Part B - Exp 4
Title: Program to implement single linked list with Insert, Delete, Search, Display
Register Number: 408CS15015
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node* link;
};

typedef struct node* NODE;

NODE first = NULL;

/* Function prototypes */
void insert(int item);
void delete();
void display();
void search();

int main()
{
    int choice, item;

    while (1)
    {
        printf("\nLinked List Operations Menu:\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Search\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the item to insert: ");
            scanf("%d", &item);
            insert(item);
            break;

        case 2:
            delete();
            break;

        case 3:
            display();
            break;

        case 4:
            search();
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice! Please enter 1-5.\n");
        }
    }

    return 0;
}

/* Insert at beginning */
void insert(int item)
{
    NODE newnode = (NODE)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    newnode->info = item;
    newnode->link = first;
    first = newnode;
    printf("Inserted %d into the list.\n", item);
}

/* Delete first node */
void delete()
{
    if (first == NULL)
    {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    NODE temp = first;
    first = first->link;
    printf("Deleted item is %d\n", temp->info);
    free(temp);
}

/* Display the linked list */
void display()
{
    if (first == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    NODE temp = first;
    printf("Elements in the list:\n");
    while (temp != NULL)
    {
        printf("%d\n", temp->info);
        temp = temp->link;
    }
}

/* Search for an element */
void search()
{
    if (first == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    int key, pos = 0, flag = 0;
    printf("Enter the value to search: ");
    scanf("%d", &key);

    NODE ptr = first;
    while (ptr != NULL)
    {
        pos++;
        if (ptr->info == key)
        {
            flag = 1;
            break;
        }
        ptr = ptr->link;
    }

    if (flag)
        printf("Element %d found at position %d.\n", key, pos);
    else
        printf("Element %d not found.\n", key);
}
