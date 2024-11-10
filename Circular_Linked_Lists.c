#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node *next;
};

// Function to traverse and print the circular linked list
void linkedListTraversal(struct Node *head) {
    struct Node *current = head;
    if (head != NULL) {
        do {
            printf("%d \n", current->data);
            current = current->next;
        } while (current != head);
    }
}

// Function to insert a node at the beginning of the circular linked list
struct Node *insertAtFirst(struct Node *head, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode; // Point to itself if the list is empty
        return newNode;
    }

    struct Node *current = head;
    while (current->next != head) {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = head;
    return newNode;
}

int main() {
    // Pointers to the nodes
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    // Allocate memory for nodes in the linked list
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Assign data to the first node and link it to the second node
    head->data = 7;
    head->next = second;

    // Assign data to the second node and link it to the third node
    second->data = 11;
    second->next = third;

    // Assign data to the third node and link it back to the head to form a circular list
    third->data = 12;
    third->next = head;

    // Insert a new node at the beginning of the list
    head = insertAtFirst(head, 23);

    // Traverse and print the circular linked list
    linkedListTraversal(head);

    return 0;
}
