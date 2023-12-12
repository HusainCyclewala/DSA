// Implement Insertion sort
#include <stdio.h>
#include <conio.h>


// MINE PERSONAL
int main()
{
    int i, j, arr[100], n, temp;
    printf("enter no of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("enter the elements: ");
        scanf("%d", &arr[i]);
    }




    for (i = 1; i < n; i++)     //i STARTS FROM 1 SINCE THE FIRST ELEMENT IS CONSIDERED SORTED.
    {
        temp = arr[i];      //TO COMPARE.
        j = i - 1;          //J IS THE SORTED ARRAY.
        while (j >= 0 && arr[j] > temp) // SO THAT J KEEPS MOVING AHEAD SINCE ITS LARGER
        {
            arr[j + 1] = arr[j];
            j--; // SO THAT J IS COMPARED WITH ALL THE PREVIOUS ELEMENTS TOO.
        }
        arr[j + 1] = temp; // AFTER ALL THE COMPARISIONS FINALLY TRANSFERING TEMP TO ARR[J].
    }





    printf("\nSorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
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

//     for (i = 1; i < n; i++)
//     {
//         temp = arr[i];
//         j = i - 1;
//         while (j >= 0 && arr[j] > temp)
//         {
//             arr[j + 1] = arr[j];
//             j--;
//         }
//         arr[j + 1] = temp;
//     }

//     printf("\nSorted array: ");
//     for (i = 0; i < n; i++)
//     {
//         printf("%d ", arr[i]);
//     }
// }


