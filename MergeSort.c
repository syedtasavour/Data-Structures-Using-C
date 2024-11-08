#include <stdio.h>

// Function to display the array
void display_array(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Function to merge two halves of the array
void merge(int arr[], int start, int mid, int end)
{
    int merged_array[end - start + 1];
    int left_index = start;
    int right_index = mid + 1;
    int merged_index = 0;

    // Merge the two halves into merged_array
    while (left_index <= mid && right_index <= end)
    {
        if (arr[left_index] <= arr[right_index])
        {
            merged_array[merged_index++] = arr[left_index++];
        }
        else
        {
            merged_array[merged_index++] = arr[right_index++];
        }
    }

    // Copy remaining elements from the left half, if any
    while (left_index <= mid)
    {
        merged_array[merged_index++] = arr[left_index++];
    }

    // Copy remaining elements from the right half, if any
    while (right_index <= end)
    {
        merged_array[merged_index++] = arr[right_index++];
    }

    // Copy the merged elements back into the original array
    for (int i = 0, j = start; i < merged_index; i++, j++)
    {
        arr[j] = merged_array[i];
    }
}

// Function to divide the array into two halves
void divide(int arr[], int start, int end)
{
    if (start >= end)    
    {
        return;
    }
    int mid = start + (end - start) / 2;
    divide(arr, start, mid);
    divide(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

int main()
{
    int array[100] = {1, 78, 3, 5, 6, 7, 8, 9, 2,7}; // Initialize the array
    int total_size = sizeof(array) / sizeof(array[0]);
    int initialized_elements = 0;

    // Calculate the number of initialized elements in the array
    for (int i = 0; i < total_size; i++)
    {
        if (array[i] != 0)
        {
            initialized_elements++;
        }
        else
        {
            break;
        }
    }

    // Display the array before sorting
    printf("Array before sorting:\n");
    display_array(array, initialized_elements);

    // Perform Merge Sort on the initialized elements
    divide(array, 0, initialized_elements - 1);

    // Display the array after sorting
    printf("Array after sorting:\n");
    display_array(array, initialized_elements);
}

/*
Time Complexity:
- The time complexity of Merge Sort is O(n log n), where n is the number of elements in the array.
- This is because the array is divided into two halves log n times, and the merging process takes O(n) time.

Space Complexity:
- The space complexity of Merge Sort is O(n) due to the temporary array used for merging.
- This additional space is required to store the merged elements temporarily.
*/