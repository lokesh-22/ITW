#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void swap(struct Node* a, struct Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void bubbleSortLinkedList(struct Node* head) {
    int swapped;
    struct Node* ptr1;
    struct Node* lptr = NULL;

    if (head == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    struct Node* a = NULL;

    push(&a, 64);
    push(&a, 34);
    push(&a, 25);
    push(&a, 12);
    push(&a, 22);
    push(&a, 11);
    push(&a, 90);

    printf("Unsorted Linked List: \n");
    printList(a);

    bubbleSortLinkedList(a);

    printf("Sorted Linked List: \n");
    printList(a);

    return 0;
}