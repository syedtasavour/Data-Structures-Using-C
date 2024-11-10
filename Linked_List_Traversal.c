#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node *next;
};

// Function to traverse and print the linked list
void linkedListTraversal(struct Node *currentNode) {
    while (currentNode != NULL) {
        printf("%d \n", currentNode->data);
        currentNode = currentNode->next;
    }
}

int main() {
    // Allocate memory for nodes in the linked list in the heap
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));

    // Initialize the data and link the nodes
    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 12;
    third->next = NULL;

    // Traverse and print the linked list
    linkedListTraversal(head);

    // Free the allocated memory
    free(head);
    free(second);
    free(third);

    return 0;
}
