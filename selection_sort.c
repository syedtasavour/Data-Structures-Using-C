#include <stdio.h>

// Function to perform selection sort on an array
void selectionSort(int arr[], int size)
{
    // Loop through each element of the array
    for (int i = 0; i < size - 1; i++)
    {
        // Assume the current element is the minimum
        int minIndex = i;

        // Find the index of the minimum element in the remaining unsorted array
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the current element
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Function to display the elements of an array
void displayArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }
}

int main()
{
    // Initialize an array with some elements
    int arr[100] = {4, 1, 2, 6, 3, 78, 5};

    // Perform selection sort on the array
    selectionSort(arr, 7);

    // Display the sorted array
    displayArray(arr, 7);

    return 0;
}

/*
Time Complexity:
- Best case: O(n^2)
- Average case: O(n^2)
- Worst case: O(n^2)

Space Complexity:
- O(1) (in-place sorting)
*/