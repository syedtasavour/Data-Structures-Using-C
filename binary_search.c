#include <stdio.h>

// Function to perform binary search on a sorted array
// Time Complexity: O(log n)
// Space Complexity: O(1)
int binary_search(int array[], int size, int target)
{
    int low = 0, mid, high = size - 1;
    
    // Loop until the search space is exhausted
    while (low <= high)
    {
        mid = (low + high) / 2; // Calculate the middle index
        
        // Check if the target is present at mid
        if (array[mid] == target)
        {
            return mid; // Target found, return the index
        }
        
        // If target is greater, ignore the left half
        if (array[mid] < target)
        {
            low = mid + 1;
        }
        // If target is smaller, ignore the right half
        else
        {
            high = mid - 1;
        }
    }
    
    return -1; // Target not found, return -1
}

int main()
{
    int array[100] = {1, 2, 3, 4, 5}; // Example array
    int size = 5; // Size of the array
    int target = 4; // Element to be searched
    
    // Perform binary search
    int result = binary_search(array, size, target);
    
    // Check the result and print appropriate message
    if (result == -1)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Element found at index %d\n", result);
    }
    
    return 0;
}