#include <stdio.h>
#include <stdlib.h>

// Define the stack structure
struct Stack {
    int size;
    int top;
    int *array;
};

// Function to check if the stack is full
char isFull(struct Stack *stack) {
    if (stack->top == stack->size - 1) {
        return 1;
    }
    return 0;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    if (stack->top == -1) {
        return 1;
    }
    return 0;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int value) {
    if (!isFull(stack)) {
        stack->top++;
        stack->array[stack->top] = value;
    } else {
        printf("Stack Overflow\n");
    }
}

// Function to pop an element from the stack
void pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is already empty\n");
    } else {
        stack->top--;
    }
}

int main() {
    // Create a stack and initialize its properties
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->size = 10;
    stack->top = -1;
    stack->array = (int *)malloc(stack->size * sizeof(int));

    // Pop an element from the stack (which is currently empty)
    pop(stack);

    // Print the top element of the stack and the top index
    if (!isEmpty(stack)) {
        printf("Top element: %d\n", stack->array[stack->top]);
    }
    printf("Top index: %d\n", stack->top);

    // Free allocated memory
    free(stack->array);
    free(stack);

    return 0;
}
