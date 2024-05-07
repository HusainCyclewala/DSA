#include <stdlib.h>
#include <stdio.h>

//------------------MINE---------------
struct node
{
    int data;
    struct node *next;
} *head, *newnode, *tail;

void create()
{
    int n, i, data;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    struct node *newnode;
    for (i = 0; i < n; i++)
    {

        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);

        if (head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        tail->next = head;
    }
}

void insertBeginning()
{
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("\nenter data to insert at beginning: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        tail->next = newnode;
    }
    else
    {
        newnode->next = head;
        tail->next = newnode;
        head = newnode;
    }
}

void insertEnd()
{
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("\nenter data to insert at the end: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        tail->next = newnode;
    }
    else
    {
        newnode->next = head;
        tail->next = newnode;
        tail = newnode;
    }
}

void insertBefore()
{
    int i = 1, pos;

    printf("\nEnter POSITION at which u want ton insert data: ");
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
        printf("\nenter data to insert: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

//----------------------NOT MINE---------------------------

void insert_before()
{
    int val, data;
    struct node *newnode, *temp, *p;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data before which node is to be inserted: ");
    scanf("%d", &val);
    printf("Enter data: ");
    scanf("%d", &data);
    newnode->data = data;
    temp = head;
    while (temp->data != val && temp->next != head)
    {
        temp = temp->next;
    }
    if (temp->data == val)
    {
        if (temp == head)
        {
            p = head;
            while (p->next != head)
            {
                p = p->next;
            }
            newnode->next = head;
            head = newnode;
            p->next = newnode;
        }
        else
        {
            temp = head;
            while (temp->data != val)
            {
                p = temp;
                temp = temp->next;
            }
            p->next = newnode;
            newnode->next = temp;
        }
    }
    else
        printf("Value not found !");
}

void insert_after()
{
    int val, data;
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data after which node is to be inserted: ");
    scanf("%d", &val);
    printf("Enter data: ");
    scanf("%d", &data);

    newnode->data = data;
    temp = head;

    while (temp->data != val && temp->next != head)
    {
        temp = temp->next;
    }
    if (temp->data == val)
    {
        newnode->next = temp->next;
        temp->next = newnode;
    }

    else
        printf("Value not found !");
}

void del()
{
    int val;
    struct node *temp, *temp1, *pre;
    printf("Enter the data to be deleted: ");
    scanf("%d", &val);

    temp = head;
    while (temp->data != val && temp->next != head)
    {
        pre = temp;
        temp = temp->next;
    }

    if (temp->data == val)
    {
        if (temp == head)
        {
            tail->next = temp->next;
            head = temp->next;
            free(temp);
        }
        else
        {
            pre->next = temp->next;
            free(temp);
        }
    }
    else{
        printf("Value not found !");
    }

}

void display()
{
    struct node *temp;
    temp = head;
    while (temp->next != head)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("%d -> %d", temp->data, head->data);
}

int main()
{
    int i;
    // int iteration = 0;
    create();
    do
    {
        printf("\nMenu:\n");
        printf("1.Insert Before\n");
        printf("2.Insert After\n");
        printf("3.Delete\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            // insert_before();
            insertBefore();
            break;

        case 2:
            // insert_after();
            insertEnd();
            break;

        case 3:
            del();
            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);
            break;

        case 6:
            insertBeginning();
            break;

        default:
            printf("Invalid Input!");
        }
        // iteration++;
    } while (1);

    return 0;
}