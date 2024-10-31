#include <stdio.h>

// Function to insert an element into an array
// Time Complexity: O(n) - where n is the number of elements in the array
// Space Complexity: O(1) - no extra space is used, only a few additional variables
int insertElement(int array[], int currentSize, int element, int capacity, int position)
{
    // Check if the array has reached its capacity
    if (currentSize >= capacity)
    {
        return -1; // Return -1 if insertion is not possible
    }

    // Shift elements to the right to make space for the new element
    for (int i = currentSize - 1; i >= position; i--)
    {
        array[i + 1] = array[i];
    }

    // Insert the new element at the specified position
    array[position] = element;
    return 1; // Return 1 to indicate successful insertion
}

// Function to display the elements of the array
// Time Complexity: O(n) - where n is the number of elements in the array
// Space Complexity: O(1) - no extra space is used, only a few additional variables
void displayArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int array[100] = {1, 2, 3, 78}; // Initialize the array with some elements
    int elementToInsert = 45; // Element to be inserted
    int position = 2; // Position at which the element is to be inserted
    int currentSize = 4; // Current size of the array
    int capacity = 100; // Capacity of the array

    // Attempt to insert the element
    int result = insertElement(array, currentSize, elementToInsert, capacity, position);

    // Check if insertion was successful
    if (result == 1)
    {
        currentSize += 1; // Increment size if insertion was successful
        printf("Insertion successful.\n");
    }
    else
    {
        printf("Insertion failed: array is full.\n");
    }

    // Display the array
    printf("Array after insertion: ");
    displayArray(array, currentSize);

    return 0;
}