// Implement bubble sort
#include <stdio.h>
#include <conio.h>

// MINE PERSONAL
int main()
{
    int i, j, n, arr[100], temp;

    printf("Enter the no of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nenter element: ");
        scanf("%d", &arr[i]);
    }

    

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    printf("sorted array is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

// int main()
// {

//     int i, j, n, arr[100], temp;
//     printf("Enter the number of elements: ");
//     scanf("%d", &n);
//     printf("Enter the elements: ");
//     for (i = 0; i < n; i++)
//     {
//         scanf("%d", &arr[i]);
//     }

//     for (i = 0; i < n - 1; i++)
//     {
//         for (j = i + 1; j < n; j++)
//         {
//             if (arr[j] < arr[i])
//             {
//                 temp = arr[j];
//                 arr[j] = arr[i];
//                 arr[i] = temp;
//             }
//         }
//     }

//     printf("Sorted array: ");
//     for (i = 0; i < n; i++)
//     {
//         printf("%d ", arr[i]);
//     }
// }
