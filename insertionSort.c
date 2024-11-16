#include <stdio.h>
#include <stdlib.h>

// Definition of the linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the linked list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Function to insert a node in sorted order
void sortedInsert(struct Node** head_ref, struct Node* new_node) {
    struct Node* current;
    if (*head_ref == NULL || (*head_ref)->data >= new_node->data) {
        new_node->next = *head_ref;
        *head_ref = new_node;
    } else {
        current = *head_ref;
        while (current->next != NULL && current->next->data < new_node->data) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

// Function to sort the linked list using insertion sort
void insertionSort(struct Node** head_ref) {
    struct Node* sorted = NULL;
    struct Node* current = *head_ref;
    while (current != NULL) {
        struct Node* next = current->next;
        sortedInsert(&sorted, current);
        current = next;
    }
    *head_ref = sorted;
}

// Main function to test the insertion sort on linked list
int main() {
    struct Node* head = NULL;

    push(&head, 5);
    push(&head, 20);
    push(&head, 4);
    push(&head, 3);
    push(&head, 30);

    printf("Linked list before sorting:\n");
    printList(head);

    insertionSort(&head);

    printf("Linked list after sorting:\n");
    printList(head);

    printf("version 4");

    return 0;
}