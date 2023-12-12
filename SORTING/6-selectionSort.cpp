// Implement selection sort
#include <stdio.h>
#include <conio.h>

// MIINE PERSONAL

int main()
{

    int i, j, n, arr[100], min, temp;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the elements: ");
        scanf("%d", &arr[i]);
    }


    

    for (i = 0; i < n - 1; i++) // FOR PASSES
    {
        min = i;                    // FOR CHECKING LATER

        for (j = i + 1; j < n; j++) // FOR TRAVERSING LINEAR SEARCH
        {
            if (arr[j] < arr[min]) // IF ELEMENT IS LESS THAN MIN.PUSH IT BEHIND
            {
                min = j;
            }
        }
        if (min != i) // IF SMALLER VALUE IS FOUND MIN WILL CHANGE.
        {
            // swap arr[i] and arr[min].
            temp = arr[i]; // SINCE a[i] is the smallest first element.
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }

    

    

        printf("\nSorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

// int main()
// {
//     int i, j, n, arr[100], min, temp;
//     printf("Enter the number of elements: ");
//     scanf("%d", &n);
//     printf("Enter the elements: ");
//     for (i = 0; i < n; i++)
//     {
//         scanf("%d", &arr[i]);
//     }

//     for (i = 0; i < n - 1; i++)
//     {
//         min = i;
//         for (j = i+1; j < n; j++)
//         {
//             if (arr[j] < arr[min])
//             {
//                 min = j;
//             }
//         }
//         if (min != i)
//         {
//             temp = arr[i];
//             arr[i] = arr[min];
//             arr[min] = temp;
//         }
//     }

//     printf("\nSorted array: ");
//     for (i = 0; i < n; i++)
//     {
//         printf("%d ", arr[i]);
//     }
// }