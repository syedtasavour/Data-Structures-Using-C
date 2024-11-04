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

// Function to partition the array
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Pivot element
    int i = low - 1; // Index of smaller element

    for (int j = low; j < high; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap arr[i + 1] and arr[high] (or pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1; // Return the partitioning index
}

// Function to perform Quick Sort
void quick_sort(int array[], int low, int high)
{
    if (low < high)
    {
        // Partition the array
        int partition_index = partition(array, low, high);

        // Recursively sort elements before and after partition
        quick_sort(array, low, partition_index - 1);
        quick_sort(array, partition_index + 1, high);
    }
}

int main()
{
    int array[100] = {1, 78, 3, 5, 6, 7, 8, 9, 2}; // Initialize the array
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

    // Perform Quick Sort on the initialized elements
    quick_sort(array, 0, initialized_elements - 1);

    // Display the array after sorting
    printf("Array after sorting:\n");
    display_array(array, initialized_elements);

    return 0;
}

/*
Time Complexity:
- Best case: O(n log n)
- Average case: O(n log n)
- Worst case: O(n^2)

Space Complexity:
- O(log n) due to the recursion stack
*/