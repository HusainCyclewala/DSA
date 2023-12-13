// Menu-driven program to implement circular queue using array
#include <stdio.h>
#include <conio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int val)
{
    if (front == -1)
    {
        front++;
        rear++;
        queue[rear] = val;
    }
    else if (front == (rear + 1) % SIZE)
    {
        printf("\nqueue is full\n");
    }
    else
    {
        if (rear == SIZE - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
            queue[rear] = val;
        }
    }
}

int dequeue()
{
    int x = -1;
    if (front == -1)
    {
        printf("Queue is empty!");
    }
    else
    {
        x = queue[front];
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
    }
    return x;
}

void display()
{
    int i = front;
    if (rear == -1)
    {
        printf("\nqueue is empty.\n");
    }
    else
    {

        while (i != rear)
        {
            printf("%d ", queue[i]);
            i = (i + 1) % SIZE;
        }
        printf("%d", queue[i]);             //to print the last element
    }
}

int main()
{
    int choice, val;
    do
    {
        printf("\n\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value you want to enqueue: ");
            scanf("%d", &val);
            enqueue(val);
            break;
        case 2:
            printf("The value dequeued is: %d", dequeue());
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        default:
            printf("Invalid choice!");
            choice = 4;
            break;
        }
    } while (choice != 4);

    return 0;
}