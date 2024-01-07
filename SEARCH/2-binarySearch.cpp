// Implement binary search
#include <stdio.h>
#include <conio.h>

// MINE PERSONAL

int binarySearch(int arr[], int n, int key)
{
    int right = n, left = 0, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (key > arr[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int i, arr[100], n, key, location;

    printf("Enter the number of elements : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter the element: ");
        scanf("%d", &arr[i]);
    }
    printf("\nenter the element to find: ");
    scanf("%d", &key);


    location = binarySearch(arr, n, key);
    
    if (location == -1)
    {
        printf("\nelemnt wrong");
    }
    else
    {
        printf("\nfound at index:%d position:%d ", location, location + 1);
    }

    return 0;
}

// int binarySearch(int arr[], int n, int key)
// {
//     int low = 0, mid, high = n;

//     while (low <= high)
//     {
//         mid = (low + high) / 2;

//         if (arr[mid] == key)
//         {
//             return mid;
//         }
//         else if (arr[mid] < key)
//         {
//             low = mid + 1;
//         }
//         else
//         {
//             high = mid - 1;
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

//     int index = binarySearch(arr, n, key);
//     if (index == -1)
//     {
//         printf("Element not found");
//     }
//     else
//     {
//         printf("Element found at index %d", index);
//     }

//     return 0;
// }
