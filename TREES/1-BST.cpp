// Implementation of Binary Search Tree
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#define sn struct Node

sn
{
    int data;
    sn *left, *right;
}
*root;

void create()
{
    int i, n, data;
    sn *newnode, *temp, *parent;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        newnode = (sn *)malloc(sizeof(sn));
        printf("\nEnter the data: ");
        scanf("%d", &data);
        newnode->data = data;
        newnode->left = newnode->right = NULL;
        parent = temp = root;

        if (root == NULL)
            root = newnode;

        else
        {
            while (temp != NULL)
            {
                parent = temp;
                if (temp->data > data)
                    temp = temp->left;

                else
                    temp = temp->right;
            }
            if (parent->data > data)
                parent->left = newnode;
            else
                parent->right = newnode;
        }
    }
}

void insert()
{
    sn *newnode = (sn *)malloc(sizeof(sn)), *temp, *parent;
    int data;
    printf("\nEnter the data: ");
    scanf("%d", &data);
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    parent = temp = root;
    if (root == NULL)
        root = newnode;

    else
    {
        while (temp != NULL)
        {
            parent = temp;
            if (temp->data > data)
                temp = temp->left;

            else
                temp = temp->right;
        }
        if (parent->data > data)
            parent->left = newnode;
        else
            parent->right = newnode;
    }
}

void deleteNode()
{
    int data;
    sn *temp, *del, *parent, *pred;
    printf("\nEnter the data of node to be deleted: ");
    scanf("%d", &data);
    parent = temp = root;

    while (temp != NULL && temp->data != data)
    {
        parent = temp;
        if (temp->data > data)
            temp = temp->left;

        else
            temp = temp->right;
    }
    if (!temp)
    {

        printf("\nNode not found!");
    }
    else
    {
        if (!temp->left && !temp->right) // leaf node no child.
        {
            if (parent->left == temp)
                parent->left = NULL;
            else
                parent->right = NULL;
        }

        else if (!temp->right) // only left child
        {
            if (parent->left == temp)
                parent->left = temp->left;
            else
                parent->right = temp->left;
        }

        else if (!temp->left) // only right child.
        {
            if (parent->left == temp)
                parent->left = temp->right;
            else
                parent->right = temp->right;
        }

        else // both child exist.
        {
            parent = temp;
            pred = temp->left;

            // Find the rightmost node in the left subtree (predecessor).
            while (pred->right != NULL)
            {
                parent = pred;
                pred = pred->right;
            }

            // Update parent pointers to detach the predecessor node.
            if (parent->left == pred)
                parent->left = pred->left;
            else
                parent->right = pred->left;

            // Copy data from the predecessor node to the node to be deleted.
            temp->data = pred->data;
            temp = pred;
        }

        free(temp);
    }
}

void mirror(sn *temp)
{
    sn *t1;
    if (temp == NULL)
    {
        mirror(temp->left);
        mirror(temp->right);
        t1 = temp->left;
        temp->left = temp->right;
        temp->right = t1;
    }
}

int totalNodes(sn *temp)
{
    if (!temp)
        return 0;
    else
    {
        return totalNodes(temp->left) + totalNodes(temp->right) + 1;
    }
}

int externalNodes(sn *temp)
{
    if (!temp)
        return 0;
    else if (temp->left == NULL && temp->right == NULL)
        return 1;
    else
        return externalNodes(temp->left) + externalNodes(temp->right);
}

int internalNodes(sn *root)
{
    return totalNodes(root) - externalNodes(root);
}

int height(sn *temp)
{
    int l, r;
    if (!temp)
        return 0;
    else
    {
        l = height(temp->left);
        r = height(temp->right);
        if (l > r)
            return l + 1;
        else
            return r + 1;
    }
}

void preOrder(sn *temp)
{
    if (temp != NULL)
    {
        printf("%d ", temp->data);
        preOrder(temp->left);
        preOrder(temp->right);
    }
}

void inOrder(sn *temp)
{
    if (temp)
    {
        inOrder(temp->left);
        printf("%d ", temp->data);
        inOrder(temp->right);
    }
}

void postOrder(sn *temp)
{
    if (temp)
    {
        postOrder(temp->left);
        postOrder(temp->right);
        printf("%d ", temp->data);
    }
}

int main()
{
    int choice;
    root = NULL;
    // clrscr();
    create();
    do
    {
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Preorder");
        printf("\n4. Inorder");
        printf("\n5. Postorder");
        printf("\n6. Mirror");
        printf("\n7. Count Internal");
        printf("\n8. Count External");
        printf("\n9. Count Total");
        printf("\n10. Height");
        printf("\n11. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            deleteNode();
            break;
        case 3:
            preOrder(root);
            break;
        case 4:
            inOrder(root);
            break;
        case 5:
            postOrder(root);
            break;
        case 6:
            mirror(root);
            break;
        case 7:
            printf("\nThe number of internal nodes are: %d", internalNodes(root));
            break;
        case 8:
            printf("\nThe number of external nodes are: %d", externalNodes(root));
            break;
        case 9:
            printf("\nThe number of total nodes are: %d", totalNodes(root));
            break;
        case 10:
            printf("\nThe height of the tree is: %d", height(root));
            break;
        case 11:
            printf("exiting program....");
            break;
        default:
            printf("Invalid choice");
            choice = 11;
        }
    } while (choice != 11);
    // getch();
    return 0;
}

//  PRACTICE
// #include <stdio.h>
// #include <stdlib.h>
// #include <malloc.h>
// #include <conio.h>

// struct node
// {
//     int data;
//     struct node *left, *right;
// } *temp, *newnode, *parent;

// void create()
// {
//     int i, n, data;
//     struct node *root;
//     printf("enter no. of nodes:");
//     scanf("%d", &n);
//     for (i = 0; i < n; i++)
//     {
//         newnode = (struct node *)malloc(sizeof(struct node));
//         printf("enter the data: ");
//         scanf("%d", &newnode->data);
//         newnode->right = newnode->left = NULL;
//         parent = temp = root;

//         if (root == NULL)
//         {
//             root = newnode;
//         }
//         else
//         {
//             while (temp != NULL)
//             {
//                 parent = temp;
//                 if (temp->data > data)
//                 {
//                     temp = temp->left;
//                 }
//                 else
//                 {
//                     temp = temp->right;
//                 }
//             }
//             if (parent->data > data)
//             {
//                 parent->left = newnode;
//             }
//             else
//             {
//                 parent->right = newnode;
//             }
//         }
//     }
// }

// int height(struct node *temp)
// {
//     int l, r;
//     if (temp == NULL)
//     {
//         return 0;
//     }
//     else
//     {
//         l = height(temp->left);
//         r = height(temp->right);
//         if (l > r)
//         {
//             return l + 1;
//         }
//         else
//         {
//             return r + 1;
//         }
//     }
// }