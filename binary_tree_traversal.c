/*
Register Number: 408CS15015
Experiment 10
Title: Binary Tree Traversal (Preorder, Inorder, Postorder)
*/

#include <stdio.h>
#include <stdlib.h>

/* Binary Tree Node Structure */
struct btree
{
    int info;
    struct btree* llink;
    struct btree* rlink;
};

typedef struct btree* NODE;

/* Function to create a new node */
NODE getnode(int val)
{
    NODE temp = (NODE)malloc(sizeof(struct btree));
    if (temp == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(0);
    }
    temp->info = val;
    temp->llink = NULL;
    temp->rlink = NULL;
    return temp;
}

/* Function to insert a node into BST */
NODE insert(int val, NODE root)
{
    if (root == NULL)
        return getnode(val);

    if (val < root->info)
        root->llink = insert(val, root->llink);
    else
        root->rlink = insert(val, root->rlink);

    return root;
}

/* Preorder traversal: Root, Left, Right */
void preorder(NODE root)
{
    if (root != NULL)
    {
        printf("%d\t", root->info);
        preorder(root->llink);
        preorder(root->rlink);
    }
}

/* Inorder traversal: Left, Root, Right */
void inorder(NODE root)
{
    if (root != NULL)
    {
        inorder(root->llink);
        printf("%d\t", root->info);
        inorder(root->rlink);
    }
}

/* Postorder traversal: Left, Right, Root */
void postorder(NODE root)
{
    if (root != NULL)
    {
        postorder(root->llink);
        postorder(root->rlink);
        printf("%d\t", root->info);
    }
}

int main()
{
    NODE root = NULL;
    int ch, val;

    while (1)
    {
        printf("\nBinary Tree Operations Menu:\n");
        printf("1. Insert Node\n2. Preorder Traversal\n3. Inorder Traversal\n4. Postorder Traversal\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter node value to insert (-1 to stop): ");
            scanf("%d", &val);
            if (val != -1)
                root = insert(val, root);
            break;

        case 2:
            if (root == NULL)
                printf("Tree is empty!\n");
            else
            {
                printf("Preorder traversal: ");
                preorder(root);
                printf("\n");
            }
            break;

        case 3:
            if (root == NULL)
                printf("Tree is empty!\n");
            else
            {
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
            }
            break;

        case 4:
            if (root == NULL)
                printf("Tree is empty!\n");
            else
            {
                printf("Postorder traversal: ");
                postorder(root);
                printf("\n");
            }
            break;

        case 5:
            exit(0);

        default:
            printf("Enter a correct option (1-5)\n");
        }
    }

    return 0;
}
