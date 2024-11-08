#include <stdio.h>
#include <stdlib.h>

// Define a structure for the stack
struct Stack {
    int size;   // Maximum size of the stack
    int top;    // Index of the top element
    int *array; // Array to store stack elements
};

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    if (stack->top == -1) {
        return 1;
    }
    return 0;
}

// Function to check if the stack is full
int isFull(struct Stack *stack) {
    if (stack->top == stack->size - 1) {
        return 1;
    }
    return 0;
}

int main() {
    // Allocate memory for the stack structure
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1; // Initialize top to -1 indicating the stack is empty
    stack->size = 10; // Set the maximum size of the stack
    stack->array = (int *)malloc(stack->size * sizeof(int)); // Allocate memory for the stack array

    // Check if the stack is empty
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack is not empty\n");
    }

    // Check if the stack is full
    if (isFull(stack)) {
        printf("Stack is full\n");
    } else {
        printf("Stack is not full\n");
    }

    // Free allocated memory
    free(stack->array);
    free(stack);

    return 0;
}