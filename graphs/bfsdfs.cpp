
#include <stdio.h>
// graph is of numbers ranging from 0 - 6

int queue[20], front = -1, rear = -1, visited[8];
int stack[20], top = -1;
int a[7][7] = {
    {0, 1, 0, 1, 0, 0, 0},
    {1, 0, 1, 1, 0, 1, 1},
    {0, 1, 0, 1, 1, 1, 0},
    {1, 1, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 0, 1},
    {0, 1, 1, 0, 0, 0, 0},
    {0, 1, 0, 0, 1, 0, 0},
};

//-------------------------- BFS (Queue)-------------------------------
void enqueue(int val)
{
    rear++;
    queue[rear] = val;
}

int dequeue()
{
    front++;
    return queue[front];
}

void bfs(int source, int n)
{
    enqueue(source);
    printf("%d ", source);
    visited[source] = 1;

    while (front <= rear)
    {
        int current = dequeue(); // 0
        visited[current] = 1;    // visited [0] = 1
        for (int i = 0; i < n; i++)
        {
            if (a[current][i]!=0 && visited[i]==0)
            {
                printf("%d ", i);
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    front = -1;
    rear = -1;

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    printf("\n");
}

// ----------------------------DFS (Stack)------------------------------
void push(int val)
{
    top++;
    stack[top] = val;
}

int pop()
{
    int poppedValue = stack[top];
    top--;
    return poppedValue;
}


void dfs(int source, int n)
{
    push(source);
    visited[source] = 1;
    printf("%d ", source);

    while (top != -1)
    {
        int current = pop();
        for (int i = 0; i < n; i++)
        {
            if (a[current][i]!=0 && visited[i]==0)
            {
                push(i);
                visited[i] = 1;
                printf("%d ", i);
            }
        }
    }
    top = -1;

    // for (int i = 0; i < n; i++)
    // {
    //     visited[i] = 0;
    // }
    // printf("\n");
}

//---------------------------MAIN-------------------------

int main()
{
    int n = 7, i, source, choice, j;
    int c;

    printf("The Adjacency Matrix is: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf(" %d", a[i][j]);
        }
        printf("\n");
    }

    do
    {
        for (i = 1; i <= n; i++)
        {
            visited[i] = 0;
            printf("%d",visited[i]);
        }

        printf("\nMenu");
        printf("\n1. BFS");
        printf("\n2. DFS");
        printf("\nEnter the choice: ");
        scanf("%d", &choice);
        printf("Enter the source vertex: ");
        scanf("%d", &source);
        switch (choice)
        {
        case 1:
            bfs(source, n);
            break;
        case 2:
            dfs(source, n);
            break;
        }
        printf("\nDo you want to continue (1/0)? ");
        scanf(" %d", &c); // Added space before %c to consume newline
    } while (c!=0);

    return 0;
}