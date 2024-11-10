#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node *next;
};

int main() {
    // Pointers to the nodes
    struct Node *head;
    struct Node *second;
    struct Node *third;

    // Allocate memory for nodes in the linked list
    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));

    // Assign data to the first node and link it to the second node
    head->data = 7;
    head->next = second;

    // Assign data to the second node and link it to the third node
    second->data = 11;
    second->next = third;

    // Assign data to the third node and mark the end of the list
    third->data = 12;
    third->next = NULL;

    // Free allocated memory (optional but good practice)
    free(head);
    free(second);
    free(third);

    return 0;
}
