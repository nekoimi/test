//
// Created by nekoimi on 2021/4/2.
//
#include <stdio.h>
#include "common_linked_list.h"

struct ListNode* newLinkedList(int val) {
    struct ListNode *result = (struct ListNode *) malloc(sizeof(struct ListNode));
    result->val = val;
    result->next = NULL;
    return result;
}

struct ListNode* insert(struct ListNode* node, int val) {
    node->next = newLinkedList(val);
    node = node->next;
    return node;
}

// 迭代法反转链表
struct ListNode* reversal_iteration(struct ListNode* head) {
    if (head == NULL && head->next == NULL) {
        return head;
    }

    struct ListNode* top = NULL;
    struct ListNode* middle = head;
    struct ListNode* bottom = head->next;

    while (true) {
        middle->next = top;
        if (bottom == NULL) {
            break;
        }
        top = middle;
        middle = bottom;
        bottom = bottom->next;
    }

    head = middle;
    return head;
}

void printLinkedList(struct ListNode *head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}
