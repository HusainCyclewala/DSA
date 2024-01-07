// Implement linear search

// MINE PERSONAL
#include <stdio.h>
#include <conio.h>

int linearSearch(int arr[], int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
            break;
        }
    }
    return -1;
}

int main()
{

    int arr[100], i, n, key, location;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter the elements: ");
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to be searched: ");
    scanf("%d", &key);

    location = linearSearch(arr, n, key);
    
    if (location == -1)
    {
        printf("\ninvalid search element");
    }
    else
    {
        printf("\nLocation at which element is present is index:%d and position:%d", location, location + 1);
    }

    return 0;
}

// #include <stdio.h>
// #include <conio.h>

// int linearSearch(int arr[], int n, int key)
// {
//     int i;
//     for (i = 0; i < n; i++)
//     {
//         if (arr[i] == key)
//         {
//             return i;
//         }
//     }

//     return -1;
// }

// int main()
// {
//     int arr[100], i, n;
//     printf("Enter the number of elements: ");
//     scanf("%d", &n);
//     printf("Enter the elements: ");
//     for (i = 0; i < n; i++)
//     {
//         scanf("%d", &arr[i]);
//     }

//     int key;
//     printf("Enter the element to be searched: ");
//     scanf("%d", &key);

//     int index = linearSearch(arr, n, key);
//     if (index == -1)
//     {
//         printf("Element not found");
//     }
//     else
//     {
//         printf("Element found at index %d and position %d", index, index + 1);
//     }
//     return 0;
// }
