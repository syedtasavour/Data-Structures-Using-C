#include <stdio.h>
#include <stdlib.h>

// Define the queue structure
struct CircularQueue
{
    int size;
    int front;
    int rear;
    int *array;
};

// Function to check if the queue is full
// Time Complexity: O(1)
// Space Complexity: O(1)
int isFull(struct CircularQueue *queue)
{
    if ((queue->rear + 1) % queue->size == queue->front)
    {
        printf("Queue Overflow\n");
        return 1;
    }
    return 0;
}

// Function to check if the queue is empty
// Time Complexity: O(1)
// Space Complexity: O(1)
int isEmpty(struct CircularQueue *queue)
{
    if (queue->front == queue->rear)
    {
        return 1;
    }
    return 0;
}

// Function to add an element to the queue
// Time Complexity: O(1)
// Space Complexity: O(1)
void enqueue(struct CircularQueue *queue, int value)
{
    if (isFull(queue))
    {
        printf("Queue is full. Cannot enqueue %d\n", value);
    }
    else
    {
        queue->rear = (queue->rear + 1) % queue->size;
        queue->array[queue->rear] = value;
        printf("Enqueued %d\n", value);
    }
}

// Function to remove an element from the queue
// Time Complexity: O(1)
// Space Complexity: O(1)
void dequeue(struct CircularQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty. Cannot dequeue\n");
    }
    else
    {
        queue->front = (queue->front + 1) % queue->size;
        printf("Dequeued %d\n", queue->array[queue->front]);
    }
}

// Function to display the elements of the queue
// Time Complexity: O(n)
// Space Complexity: O(1)
void display(struct CircularQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements:\n");
        int i = (queue->front + 1) % queue->size;
        while (i != (queue->rear + 1) % queue->size)
        {
            printf("%d ", queue->array[i]);
            i = (i + 1) % queue->size;
        }
        printf("\n");
    }
}

int main()
{
    // Initialize the queue
    struct CircularQueue queue;
    queue.size = 5; // Increased size to accommodate 4 elements
    queue.front = 0;
    queue.rear = 0;
    queue.array = (int *)malloc(queue.size * sizeof(int));

    // Perform operations
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    dequeue(&queue);
    enqueue(&queue, 50);
    enqueue(&queue, 60);
    display(&queue);

    // Free allocated memory
    free(queue.array);

    return 0;
}
