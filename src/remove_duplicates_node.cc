//
// Created by nekoimi on 2021/4/8.
//
#include <stdio.h>
#include <map>
#include "remove_duplicates_node.h"

struct ListNode *deleteDuplicates(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode *cur = head;
    while (cur->next != NULL) {
        if (cur->val == cur->next->val) {
            cur->next = cur->next->next;
        } else {
            cur = cur->next;
        }
    }
    return head;
}

int *reversePrint(struct ListNode *head, int *returnSize) {
    int count = 0;
    struct ListNode *slow = NULL;
    struct ListNode *next = NULL;
    while (head != NULL) {
        next = head->next;
        head->next = slow;
        slow = head;
        head = next;
        count++;
    }
    int *res = (int *) malloc(count * sizeof(int));
    for (int j = 0; j < count; ++j) {
        res[j] = slow->val;
        slow = slow->next;
    }
    *returnSize = count;
    return res;
}

int *reversePrint2(struct ListNode *head, int *returnSize) {
    int count = 0;
    struct ListNode *p = head;
    while (p != NULL) {
        p = p->next;
        count++;
    }
    *returnSize = count;
    int *res = (int *) calloc(count, sizeof(int));
    for (int j = count - 1; j >= 0; j--) {
        res[j] = head->val;
        head = head->next;
    }
    return res;
}

void runRemoveDuplicatesNode() {
    struct ListNode *head = newLinkedList(1);
    struct ListNode *node = head;
    node = insert(node, 1);
    node = insert(node, 2);
    node = insert(node, 2);
    insert(node, 9);
    printLinkedList(head);
    head = deleteDuplicates(head);
    printLinkedList(head);
}
