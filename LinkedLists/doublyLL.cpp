//--------------MINE-----------

#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
} *head, *newnode, *tail;

void create()
{
    head = 0;
    // struct node *temp;
    int choice = 1;
    while (choice != 0)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Welcome to my Doubly Linked List\n");
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;
        if (head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }

        printf("\nDo u want to continue? \nEnter 1 for yes 0 for no: ");
        scanf("%d", &choice);
    }
}

void insertBeginning()
{
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("\nenter data to insert at beginning: ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {

        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }
}

void insertEnd()
{
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("\nenter data to insert at the end: ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = NULL;

    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}

void insertBefore()
{
    int i = 1, pos;

    printf("\nEnter position at which u want ton insert data: ");
    scanf("%d", &pos);
    if (pos <= 0)
    {
        printf("Invalid position");
    }
    else if (pos == 1)
    {
        insertBeginning();
    }
    else
    {
        struct node *temp;
        temp = head;
        newnode = (struct node *)malloc(sizeof(struct node));

        if (newnode == NULL)
        {
            printf("Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }

        printf("\nenter data to insert: ");
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;

        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->next->prev = newnode; // accesing the node after the position.
    }
}

void insertAfter()
{
    int i = 1, pos;

    printf("\nEnter position at which u want ton insert data: ");
    scanf("%d", &pos);
    if (pos <= 0)
    {
        printf("Invalid position");
    }
    else
    {
        struct node *temp, *nextNode;
        temp = head;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\nenter data to insert: ");
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;

        while (i < pos)
        {
            temp = temp->next;
            i++;
        }

        nextNode = temp->next;

        newnode->prev = temp;
        newnode->next = nextNode;
        temp->next = newnode;

        if (nextNode != NULL)
        {
            nextNode->prev = newnode;
        }
        else
        {
            // If inserting after the last position, update the tail
            tail = newnode;
        }
    }
}

// ----------------DELETE---------------
void deleteBeginning()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("list empty\n");
    }
    else if (head == tail)
    {
        head = tail = NULL;
        free(temp);
    }
    else
    {
        temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
}

void deleteEnd()
{
    struct node *temp;
    if (tail == 0)
    {
        printf("list empty\n");
    }
    else if (head == tail)
    {
        head = tail = NULL;
        free(temp);
    }
    else
    {
        temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(temp);
    }
}

void deleteFromPosition()
{
    int pos, i = 1;
    struct node *temp;
    temp = head;
    printf("Enter position to delete:  ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        deleteBeginning();
    }
    else
    {

        while (i < pos)
        {
            temp = temp->next;
            i++;
        }

        if (temp->next == NULL)
        {
            deleteEnd();
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
        }
    }
}

void display()
{
    struct node *temp;
    temp = head;

    while (temp != NULL)
    {
        if (temp->next != NULL)
        {
            printf("%d <--> ", temp->data);
        }
        else
        {
            printf("%d", temp->data);
        }
        temp = temp->next;
    }
}


int main()
{
    int choice;
    create();
    do
    {
        printf("\nMenu:\n");
        printf("1.Display\n");
        printf("2.Insert Beginning\n");
        printf("3.Insert End\n");
        printf("4.Insert Before\n");
        printf("5.Insert After\n");
        printf("6.Delete From Beginning\n");
        printf("7.Delete From End\n");
        printf("8.Delete from Position\n");
        printf("9.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display();
            break;

        case 2:
            insertBeginning();
            break;

        case 3:
            insertEnd();
            break;

        case 4:
            insertBefore();
            break;

        case 5:
            insertAfter();
            break;

        case 6:
            deleteBeginning();
            break;

        case 7:
            deleteEnd();
            break;

        case 8:
            deleteFromPosition();
            break;

        case 9:
            // Free the allocated memory before exiting
            while (head != NULL)
            {
                struct node *temp = head;
                head = head->next;
                free(temp);
            }
            exit(0);
            break;

        default:
            printf("Invalid Input!");
        }

    } while (choice);

    return 0;
}

// #include <stdlib.h>
// #include <stdio.h>

// struct Node
// {
//     int data;
//     struct Node *pre, *next;
// } *head;

// void create()
// {
//     int no_of_nodes, i, data;
//     printf("Enter number of nodes: ");
//     scanf("%d", &no_of_nodes);
//     struct Node *newNode, *temp;

//     for (i = 0; i < no_of_nodes; i++)
//     {

//         newNode = (struct Node *)malloc(sizeof(struct Node));
//         printf("Enter data: ");
//         scanf("%d", &data);
//         newNode->data = data;
//         newNode->next = NULL;

//         if (head == NULL)
//         {
//             head = newNode;
//             newNode->pre = NULL;
//         }
//         else
//         {
//             temp = head;
//             while (temp->next != NULL)
//             {
//                 temp = temp->next;
//             }
//             temp->next = newNode;
//             newNode->pre = temp;
//         }
//     }
// }

// void insert_before()
// {
//     int val, data;
//     struct Node *newNode, *temp, *p;
//     printf("Enter data before which node is to be inserted: ");
//     scanf("%d", &val);
//     printf("Enter data:");
//     scanf("%d", &data);

//     newNode = (struct Node *)malloc(sizeof(struct Node));
//     newNode->data = data;
//     temp = head;
//     while (temp->data != val)
//     {
//         p = temp;
//         temp = temp->next;
//     }
//     if (temp->data == val)
//     {
//         if (temp == head)
//         {
//             newNode->next = head;
//             head->pre = newNode;
//             head = newNode;
//         }
//         else
//         {
//             while (temp->data != val)
//             {
//                 p = temp;
//                 temp = temp->next;
//             }
//             p->next = newNode;
//             newNode->pre = p;
//             newNode->next = temp;
//             temp->pre = newNode;
//         }
//     }

//     else
//         printf("Value not found !");
// }

// void insert_after()
// {
//     int val, data;
//     struct Node *newNode, *temp, *post;
//     printf("Enter data before which node is to be inserted: ");
//     scanf("%d", &val);
//     printf("Enter data:");
//     scanf("%d", &data);

//     newNode = (struct Node *)malloc(sizeof(struct Node));
//     newNode->data = data;

//     temp = head;
//     while (temp->data != val)
//     {
//         temp = temp->next;
//     }
//     post = temp->next;
//     if (temp->data == val)
//     {
//         newNode->pre = temp;
//         temp->next = newNode;

//         if (post != NULL)
//         {
//             post->pre = newNode;
//             newNode->next = post;
//         }
//     }

//     else
//         printf("Value not found !");
// }

// void del()
// {
//     struct node *temp, p, post;
//     int val;
//     printf("Enter the element to be deleted: ");
//     scanf("%d", &val);

//     temp = head;
//     while (temp->data != val && temp->next != NULL)
//     {
//         p = temp;
//         temp = temp->next;
//     }
//     post = temp->next;
//     if (temp->data == val)
//     {
//         if (temp == head)
//         {
//             head= temp->next;
//             free(temp);
//         }
//         else
//         {
//             p->next = post;
//             post->pre = p;
//             free(temp);
//         }
//     }

//     else
//         printf("Value not found !");
// }

// void display()
// {
//     struct Node *temp;
//     temp = head;
//     while (temp != NULL)
//     {
//         if (temp->next != NULL)
//         {
//             printf("%d <--> ", temp->data);
//         }
//         else
//         {
//             printf("%d", temp->data);
//         }
//         temp = temp->next;
//     }
// }

// int main()
// {
//     int i, iteration = 0;
//     create();
//     do
//     {
//         printf("\nMenu:\n");
//         printf("1.Insert Before\n");
//         printf("2.Insert After\n");
//         printf("3.Delete\n");
//         printf("4.Display\n");
//         printf("5.Exit\n");
//         printf("Enter choice: ");
//         scanf("%d", &i);
//         switch (i)
//         {
//         case 1:
//             insert_before();
//             break;

//         case 2:
//             insert_after();
//             break;

//         case 3:
//             del();
//             break;

//         case 4:
//             display();
//             break;

//         case 5:
//             exit(0);
//             break;

//         default:
//             printf("Invalid Input!");
//         }
//         iteration++;
//     } while (iteration < 8);

//     return 0;
// }