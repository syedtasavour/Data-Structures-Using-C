#include <stdio.h>

// Function to perform insertion sort on an array
void Insertion_Sort(int array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int current_element = array[i];
        int previous_index = i - 1;

        // Shift elements of the sorted segment to the right to make space for the current element
        while (previous_index >= 0 && array[previous_index] > current_element)
        {
            array[previous_index + 1] = array[previous_index];
            previous_index--;
        }
        array[previous_index + 1] = current_element;
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
    int array[100] = {1, 78, 3, 5, 6, 7, 8, 9, 2};
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

    // Perform insertion sort on the initialized elements
    Insertion_Sort(array, initialized_elements);

    // Display the sorted array
    display_array(array, initialized_elements);

    return 0;
}

/*
Time Complexity:
- Best Case: O(n) when the array is already sorted.
- Average Case: O(n^2) when the array elements are in random order.
- Worst Case: O(n^2) when the array is sorted in reverse order.

Space Complexity:
- O(1) as the sorting is done in-place.
*/