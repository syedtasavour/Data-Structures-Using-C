#include <stdio.h>

// Function to remove an element from the array
// Time Complexity: O(n), Space Complexity: O(1)
int removeElement(int arr[], int elementToRemove, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == elementToRemove) {
            // Shift elements to the left to fill the gap
            for (int j = i; j < size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            return 1; // Element removed successfully
        }
    }
    return -1; // Element not found
}

// Function to display the array
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int array[100] = {1, 2, 3, 78}; // Initial array
    int elementToRemove = 3; // Element to be removed
    int arraySize = 4; // Initial size of the array

    int result = removeElement(array, elementToRemove, arraySize);
    if (result == 1) {
        arraySize -= 1; // Decrease size after removal
        displayArray(array, arraySize); // Display the updated array
    } else {
        printf("Failed To Remove Element\n");
    }

    return 0;
}
