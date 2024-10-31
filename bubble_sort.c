#include <stdio.h>

/*
Time Complexity:
- Best case: O(n) when the array is already sorted.
- Average case: O(n^2) when the array elements are in random order.
- Worst case: O(n^2) when the array is sorted in reverse order.

Space Complexity:
- O(1) as the sorting is done in place and no extra space is required.
*/

// Function to perform bubble sort on an array
void bubble_sort(int array[], int length)
{
    int temp;
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                // Swap array[j] and array[j + 1]
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Function to display the elements of an array
void display_array(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int array[100] = {1, 3, 5, 6, 7, 8, 9, 2};
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

    // Perform bubble sort on the initialized elements
    bubble_sort(array, initialized_elements);

    // Display the sorted array
    display_array(array, initialized_elements);

    return 0;
}