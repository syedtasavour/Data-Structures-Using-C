#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Time Complexity: O(n) where n is the number of nodes
// Space Complexity: O(1)
void traverseLinkedList(struct Node* headNode) {
    while (headNode != NULL) {
        printf("%d \n", headNode->data);
        headNode = headNode->next;
    }
}

// Time Complexity: O(1)
// Space Complexity: O(1)
struct Node* insertAtBeginning(struct Node* headNode, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->next = headNode;
    newNode->data = newData;
    return newNode;
}

// Time Complexity: O(n) where n is the position to insert
// Space Complexity: O(1)
struct Node* insertAtPosition(struct Node* headNode, int position, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* currentNode = headNode;
    int currentPosition = 0;
    
    // Traverse to the position before insertion point
    while (currentPosition != position - 1) {
        currentNode = currentNode->next;
        currentPosition++;
    }
    
    newNode->data = newData;
    newNode->next = currentNode->next;
    currentNode->next = newNode;
    return headNode;
}

// Time Complexity: O(n) where n is the number of nodes
// Space Complexity: O(1)
struct Node* insertAtLast(struct Node* headNode, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* currentNode = headNode;
    
    // Traverse to the last node
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    
    currentNode->next = newNode;
    newNode->next = NULL;
    newNode->data = newData;
    return headNode;
}

// Time Complexity: O(1)
// Space Complexity: O(1)
struct Node* insertAfterNode(struct Node* headNode, struct Node* previousNode, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = previousNode->next;
    previousNode->next = newNode;
    return headNode;
}

int main() {
    // Initialize the linked list
    struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* secondNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* thirdNode = (struct Node*)malloc(sizeof(struct Node));
    
    // Populate initial linked list
    headNode->data = 7;
    headNode->next = secondNode;

    secondNode->data = 11;
    secondNode->next = thirdNode;

    thirdNode->data = 12;
    thirdNode->next = NULL;

    // Demonstrate different insertion operations
    headNode = insertAtBeginning(headNode, 5);           // Insert 5 at start
    headNode = insertAtPosition(headNode, 1, 12);        // Insert 12 at position 1
    headNode = insertAtLast(headNode, 13);              // Insert 13 at end
    headNode = insertAfterNode(headNode, secondNode, 55); // Insert 55 after secondNode

    // Display the final linked list
    printf("Final Linked List:\n");
    traverseLinkedList(headNode);
    
    return 0;
}