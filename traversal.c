/**
 * @file traversal.c
 * @brief This file contains a function to display elements of an array.
 * 
 * The display function prints each element of the given array on a new line.
 * 
 * @details
 * This function takes an array and its size as input and prints each element
 * of the array on a new line. It is a simple traversal function that iterates
 * through the array elements and prints them.
 * 
 * @note The function assumes that the array has at least 'n' elements.
 * 
 * @complexity
 * Time Complexity: O(n), where n is the number of elements in the array.
 * Space Complexity: O(1), as it uses a constant amount of extra space.
 * 
 * @author Syed Tasavour
 * @date 2023-10-05
 */

#include <stdio.h>

/**
 * @brief Displays elements of an array.
 * 
 * This function takes an array and its size as input and prints each element
 * of the array on a new line.
 * 
 * @param arr The array to be displayed.
 * @param n The number of elements in the array.
 */
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
}

int main()
{
    int arr[100] = {1, 2, 6, 78};
    display(arr, 4);
    return 0;
}