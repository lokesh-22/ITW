#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* merge(struct ListNode* l1, struct ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    if (l1->val < l2->val) {
        l1->next = merge(l1->next, l2);
        return l1;
    } else {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

struct ListNode* getMiddle(struct ListNode* head) {
    if (!head) return head;

    struct ListNode* slow = head;
    struct ListNode* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

struct ListNode* mergeSort(struct ListNode* head) {
    if (!head || !head->next) return head;

    struct ListNode* middle = getMiddle(head);
    struct ListNode* nextToMiddle = middle->next;

    middle->next = NULL;

    struct ListNode* left = mergeSort(head);
    struct ListNode* right = mergeSort(nextToMiddle);

    return merge(left, right);
}

void printList(struct ListNode* head) {
    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

void push(struct ListNode** head_ref, int new_data) {
    struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_node->val = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    struct ListNode* head = NULL;


    push(&head, 15);
    push(&head, 10);
    push(&head, 5);
    push(&head, 20);
    push(&head, 3);
    push(&head, 2);

    printf("Linked List before sorting:\n");
    printList(head);

    head = mergeSort(head);

    printf("Linked List after sorting:\n");
    printList(head);

    return 0;
}