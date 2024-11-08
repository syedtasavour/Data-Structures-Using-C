#include <stdio.h>
#include <stdlib.h>

// Define the queue structure
struct Queue {
    int size;
    int front;
    int rear;
    int *array;
};

// Function to check if the queue is full
// Time complexity: O(1)
int isFull(struct Queue *queue) {
    return queue->rear == queue->size - 1;
}

// Function to check if the queue is empty
// Time complexity: O(1)
int isEmpty(struct Queue *queue) {
    return queue->rear == -1;
}

// Function to add an element to the queue
// Time complexity: O(1)
void enqueue(struct Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue %d\n", value);
    } else {
        queue->rear++;
        queue->array[queue->rear] = value;
        printf("Enqueued %d\n", value);
    }
}

// Function to remove an element from the queue
// Time complexity: O(1)
void dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue\n");
    } else {
        queue->front++;
        printf("Dequeued %d\n", queue->array[queue->front]);
    }
}

// Function to display the elements of the queue
// Time complexity: O(n), where n is the number of elements in the queue
void display(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements:\n");
        for (int i = queue->front + 1; i <= queue->rear; i++) {
            printf("%d ", queue->array[i]);
        }
        printf("\n");
    }
}

int main() {
    // Initialize the queue
    struct Queue queue;
    queue.size = 10;
    queue.front = -1;
    queue.rear = -1;
    queue.array = (int *)malloc(queue.size * sizeof(int));

    // Perform operations on the queue
    enqueue(&queue, 2);
    enqueue(&queue, 32);
    dequeue(&queue);
    display(&queue);

    // Free the allocated memory
    free(queue.array);

    return 0;
}
