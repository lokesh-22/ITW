
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get the maximum value in an array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Function to perform counting sort on an array based on a specific digit
// Modify countingSort in C
void countingSort(int arr[], int n, int exp) {
    int* output = (int*)malloc(n * sizeof(int));  // Dynamically allocate memory for output
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    free(output);  // Free allocated memory
}


// Radix Sort function for arrays
void radixSortArray(int arr[], int n) {
    int max = getMax(arr, n);

    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

// Node structure for linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to get the maximum value in a linked list
int getMaxLinkedList(struct Node* head) {
    int max = head->data;
    struct Node* current = head->next;
    while (current != NULL) {
        if (current->data > max)
            max = current->data;
        current = current->next;
    }
    return max;
}

// Function to perform counting sort on a linked list based on a specific digit
void countingSortLinkedList(struct Node** headRef, int exp) {
    struct Node* output = NULL;
    struct Node* current = *headRef;
    int count[10] = {0};

    while (current != NULL) {
        count[(current->data / exp) % 10]++;
        current = current->next;
    }

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    current = *headRef;
    while (current != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = current->data;
        newNode->next = NULL;

        int index = --count[(current->data / exp) % 10];
        if (output == NULL) {
            output = newNode;
        } else {
            struct Node* temp = output;
            while (index-- > 0 && temp->next != NULL)
                temp = temp->next;
            newNode->next = temp->next;
            temp->next = newNode;
        }
        current = current->next;
    }

    *headRef = output;
}

// Radix Sort function for linked lists
void radixSortLinkedList(struct Node** headRef) {
    int max = getMaxLinkedList(*headRef);

    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSortLinkedList(headRef, exp);
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to print a linked list
void printLinkedList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to insert a new node at the end of the linked list
void append(struct Node** headRef, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *headRef;
    newNode->data = newData;
    newNode->next = NULL;

    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = newNode;
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    printArray(arr, n);

    radixSortArray(arr, n);
    printf("Sorted array: ");
    printArray(arr, n);

    struct Node* head = NULL;
    append(&head, 170);
    append(&head, 45);
    append(&head, 75);
    append(&head, 90);
    append(&head, 802);
    append(&head, 24);
    append(&head, 2);
    append(&head, 66);

    printf("Original linked list: ");
    printLinkedList(head);

    radixSortLinkedList(&head);
    printf("Sorted linked list: ");
    printLinkedList(head);

    return 0;
}