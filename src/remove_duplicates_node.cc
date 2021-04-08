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
