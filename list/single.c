
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

void display(struct ListNode* head)
{
    struct ListNode* current = head;

    while(current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

void push(struct ListNode* head, int val)
{
    struct ListNode* current = head;
    while(current->next != NULL) {
        current = current->next;
    }

    current->next = (struct ListNode*)malloc(sizeof(struct ListNode));

    current->next->val = val;
    current->next->next = NULL;
}

struct ListNode* traverse(struct ListNode* head)
{
    if (head == NULL) {
        return NULL;
    }

    struct ListNode* newHead = NULL;

    while(head != NULL) {
        struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));

        temp->val = head->val;

        if (newHead == NULL) {
            temp->next = NULL;
        } else {
            temp->next = newHead;
        }

        newHead = temp;

        head = head->next;
    }

    return newHead;
}

int main(int argc, char const *argv[])
{
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));

    if (head == NULL) {
        return 1;
    }

    head->val = 1;
    head->next = NULL;

    push(head, 2);
    push(head, 3);
    push(head, 4);
    push(head, 5);
    push(head, 6);

    display(head);

    struct ListNode* newHead = traverse(head);

    printf("\n");

    display(newHead);
}