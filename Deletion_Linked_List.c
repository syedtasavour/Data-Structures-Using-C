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

// Function to delete the first node of the linked list
// Time Complexity: O(1)
// Space Complexity: O(1)
struct Node *deleteFirst(struct Node *head) {
    if (head == NULL) return NULL;
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete a node at a given index (0-based) in the linked list
// Time Complexity: O(n)
// Space Complexity: O(1)
struct Node *deleteBetween(struct Node *head, int index) {
    if (head == NULL || index < 0) return head;
    if (index == 0) return deleteFirst(head);

    struct Node *current = head;
    for (int i = 0; i < index - 1 && current->next != NULL; i++) {
        current = current->next;
    }

    if (current->next == NULL) return head;

    struct Node *temp = current->next;
    current->next = temp->next;
    free(temp);
    return head;
}

// Function to delete the last node of the linked list
// Time Complexity: O(n)
// Space Complexity: O(1)
struct Node *deleteLast(struct Node *head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node *current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
    return head;
}

// Function to delete the first node with a given value in the linked list
// Time Complexity: O(n)
// Space Complexity: O(1)
struct Node *deleteValue(struct Node *head, int value) {
    if (head == NULL) return NULL;
    if (head->data == value) return deleteFirst(head);

    struct Node *current = head;
    while (current->next != NULL && current->next->data != value) {
        current = current->next;
    }

    if (current->next == NULL) return head;

    struct Node *temp = current->next;
    current->next = temp->next;
    free(temp);
    return head;
}

int main() {
    // Allocate memory for nodes in the linked list in the heap
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fifth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *sixth = (struct Node *)malloc(sizeof(struct Node));

    // Initialize the data and link the nodes
    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 12;
    third->next = fourth;

    fourth->data = 15;
    fourth->next = fifth;

    fifth->data = 44;
    fifth->next = sixth;

    sixth->data = 34;
    sixth->next = NULL;

    // Traverse and print the linked list
    printf("Original Linked List:\n");
    linkedListTraversal(head);

    // Delete the first node
    head = deleteFirst(head);
    printf("After Deleting First Node:\n");
    linkedListTraversal(head);

    // Delete a node at index 2
    head = deleteBetween(head, 2);
    printf("After Deleting Node at Index 2:\n");
    linkedListTraversal(head);

    // Delete the last node
    head = deleteLast(head);
    printf("After Deleting Last Node:\n");
    linkedListTraversal(head);

    // Delete the node with value 11
    head = deleteValue(head, 11);
    printf("After Deleting Node with Value 11:\n");
    linkedListTraversal(head);

    return 0;
}
